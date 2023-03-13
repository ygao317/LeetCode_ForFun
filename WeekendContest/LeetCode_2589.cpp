class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const auto &t1, const auto &t2){ return t1[1] < t2[1]; });
        int line[2001] = {};
        for (auto &t: tasks) {
            int st=t[0], ed =t[1], d=t[2];
            d -= count(begin(line) + st, begin(line) + ed +1, true);
            for (int i = ed; d>0; --i){
                d -= !line[i];
                line[i] = true;
            }
        }
        return count(begin(line), end(line), true);
    }
};
