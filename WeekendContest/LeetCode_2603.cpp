class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int sz = coins.size();
        vector<vector<int>> al(sz);
        for (const auto &e : edges) {
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }
        vector<int> cnt(sz), steps(sz, 30000), q;
        for (int i = 0; i < sz; ++i) {
            cnt[i] = al[i].size();
            if (cnt[i] == 1)
                q.push_back(i);
        }
        while (!q.empty()) {
            auto i = q.back(); q.pop_back();
            if (--steps[i]) {
                --sz;
                for (int j : al[i]) {
                    steps[j] = min(steps[j], min(steps[i], coins[i] ? 2 : 30000));
                    if (--cnt[j] == 1)
                        q.push_back(j);
                }
            }
        }
        return 2 * max(0, sz - 1);
    }
};
