class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        for (auto& v: grid)
            sort(v.begin(), v.end());
        
        int ans = 0;
        for (int j = n-1; j>=0; --j){
            int lm = 0;
            for (int i=0; i<m; ++i)
                lm = max(lm, grid[i][j]);
            ans += lm;
        }
        
        return ans;
    }
};
