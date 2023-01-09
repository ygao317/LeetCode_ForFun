class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        priority_queue<pair<int, int>> bq_l, bq_r; // <efficiency, index>
        set<pair<int, int>> wh_l, wh_r; // <time, index>
        int bridge_t = 0;
        for (int i = 0; i < k; ++i) // at time o, all waiting at the left
            bq_l.push({time[i][0] + time[i][2], i});
        while (n || bq_r.size() + wh_r.size()) { // n > 0 or pending shift from right to left
            while (!wh_l.empty() && begin(wh_l)->first <= bridge_t) { // join the waiting queue on the left
                int i = begin(wh_l)->second;
                bq_l.push({time[i][0] + time[i][2], i});
                wh_l.erase(begin(wh_l));
            }
            while (!wh_r.empty() && begin(wh_r)->first <= bridge_t) { // join the waiting queue on the right
                int i = begin(wh_r)->second;
                bq_r.push({time[i][0] + time[i][2], i});
                wh_r.erase(begin(wh_r));
            }
            if (!bq_r.empty()) { // right queue has priority
                int i = bq_r.top().second; bq_r.pop();
                bridge_t += time[i][2];
                wh_l.insert({bridge_t + time[i][3], i});
            }
            else if (!bq_l.empty() && n) {   // left queue later
                int i = bq_l.top().second; bq_l.pop();
                --n;
                bridge_t += time[i][0];
                wh_r.insert({bridge_t + time[i][1], i});        
            }
            else // go to the next timepoint
                bridge_t = min(!wh_l.empty() && n ? begin(wh_l)->first : INT_MAX,
                                !wh_r.empty() ? begin(wh_r)->first : INT_MAX);
        }
        return bridge_t;
    }
};
