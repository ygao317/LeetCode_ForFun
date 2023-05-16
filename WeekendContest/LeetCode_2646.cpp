class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        unordered_map<int, vector<int>> es; // prepare edges map
        for (auto &e: edges){
            es[e[0]].push_back(e[1]);
            es[e[1]].push_back(e[0]);
        }
        
        vector<int> cnt(n, 0); // count the apperance
        function<bool(int, int, int)> dfs = [&](int s, int t, int p) {
            if (s == t){ ++cnt[s]; return true; }
            for (auto& d: es[s]){
                if (d == p) continue;
                if (dfs(d, t, s)){ ++cnt[s]; return true;}
            }
            return false;
        };
        for (auto &t: trips) dfs(t[0], t[1], -1);
        
        vector<vector<int>> dp(n, {-1, -1}); // top down dp 
        function<int(int, int, int)> td = [&](int s, int p, int h) {
            if (dp[s][h] != -1) return dp[s][h];
            int res = price[s] * cnt[s] / (h?2:1);
            for (auto &d: es[s]){
                if (d == p) continue;
                if (h) res += td(d, s, 0); else res += min(td(d,s,1), td(d,s,0));
            }
            return dp[s][h] = res;
        };
        return min(td(0,-1,0), td(0,-1,1));
    }
};
