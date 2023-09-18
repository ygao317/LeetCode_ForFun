class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_map<int, int>> G;
        for (auto& e : edges) {
            G[e[0]][e[1]] = 0, G[e[1]][e[0]] = 1;
        }
        vector<int> res(n, -1);

        function<int(int, int)> dp = [&](int i, int j) {
            int cur = 0;
            for (auto& k : G[j]) {
                if (k.first == i) continue;
                cur += dp(j, k.first) + k.second;
            }
            return cur;
        };

        function<void(int, int)> dfs = [&](int i, int v) {
            res[i] = v;
            for (auto& j : G[i])
                if (res[j.first] < 0)
                    dfs(j.first, v - j.second + G[j.first][i]);
        };

        dfs(0, dp(-1, 0));
        return res;
    }
};
