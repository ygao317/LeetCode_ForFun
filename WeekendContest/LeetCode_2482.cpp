class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ro(m, 0), co(n, 0);
        for (int i = 0; i<m; ++i)
            for (int j=0; j<n; ++j)
                if (grid[i][j] == 1)
                    ro[i]++, co[j]++;
        
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i<m; ++i)
            for (int j=0; j<n; ++j)
                ans[i][j] = ro[i] + co[j] + ro[i] + co[j] - m - n;
        
        return ans;
    }
};
