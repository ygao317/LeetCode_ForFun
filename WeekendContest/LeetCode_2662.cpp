class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        int n = specialRoads.size();
        vector<vector<int>> nodes(2*n+2); // 0 = start, 2n+1 = targe, i => i+n for special path
        priority_queue<pair<int,int>> pq;
        auto enqueue = [&](int i) { pq.push({-nodes[i][2], i}); };

        nodes[0] = {start[0], start[1], 0};
        nodes[2*n+1] = {target[0], target[1], abs(target[0]-start[0])+abs(target[1]-start[1])}; enqueue(2*n+1);
        for (int i=1; i<= n; ++i){
            nodes[i] = {specialRoads[i-1][0], specialRoads[i-1][1], abs(specialRoads[i-1][0]-start[0])+abs(specialRoads[i-1][1]-start[1])}; enqueue(i);
            nodes[i+n] = {specialRoads[i-1][2], specialRoads[i-1][3], abs(specialRoads[i-1][2]-start[0])+abs(specialRoads[i-1][3]-start[1])}; enqueue(i+n);
        }
        
        while (!pq.empty()){
            auto wn = pq.top(); pq.pop();
            int w = -wn.first, d = wn.second;
            if (w > nodes[d][2]) continue; // not valid any more
            if (d <= n && w + specialRoads[d-1][4] < nodes[d+n][2]){ // special path
                nodes[d+n][2] = w + specialRoads[d-1][4];
                enqueue(d+n);
            }
            for (int i = 1; i < 2*n+2; ++i){ // normal path
                if (i == d) continue;
                int dist = abs(nodes[i][0] - nodes[d][0]) + abs(nodes[i][1] - nodes[d][1]);
                if (nodes[i][2] > w + dist){
                    nodes[i][2] = w + dist;
                    pq.push({-nodes[i][2], i});
                    enqueue(i);
                }
            }
        }

        return nodes[2*n+1][2];
    }
};
