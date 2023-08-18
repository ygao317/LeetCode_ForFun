class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> m(n);
        for (auto& r: roads){
            m[r[0]].insert(r[1]);
            m[r[1]].insert(r[0]);
        }

        int res = 0;
        for (int i = 0; i<n; ++i)
            for (int j=i+1; j<n; ++j)
                res = max(res, (int)(m[i].size() + m[j].size() - m[i].count(j)));
        
        return res;
    }
};
