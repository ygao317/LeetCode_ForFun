class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(m,0);
        for (int j = n-2; j >=0; --j){ // backward
            vector<int> tmp(m, 0);
            for (int i=0; i < m; ++i){
                if (grid[i][j] < grid[i][j+1]) tmp[i] = max(tmp[i], dp[i]+1);
                if (i-1>=0 && grid[i][j] < grid[i-1][j+1]) tmp[i] = max(tmp[i], dp[i-1]+1);
                if (i+1<m && grid[i][j] < grid[i+1][j+1]) tmp[i] = max(tmp[i], dp[i+1]+1);
            }
            tmp.swap(dp);
        }
        return *max_element(dp.begin(), dp.end());
    }
};
