class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> G(n); // build up the graph
        for (auto& e : edges) {
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        int inf = 10000, res = inf;
        auto root = [&](int i) { // helper function
            vector<int> dis(n, inf);
            dis[i] = 0;
            queue<int> bfs{{i}};
            while (!bfs.empty()) {
                auto i = bfs.front(); bfs.pop();
                int res = inf;
                for (auto j : G[i]) {
                    if (dis[j] == inf) {
                        dis[j] = 1 + dis[i];
                        bfs.push(j);
                    } else if (dis[i] <= dis[j]) {
                        res = min(res, dis[i] + dis[j] + 1);
                    }
                }
                if (res < inf) return res;
            }
            return inf;
        };
        for (int i = 0; i < n; ++i){
            //cout << i << " " << root(i) << endl;
            res = min(res, root(i));
        }
        return res < inf ? res : -1;
    }
};
