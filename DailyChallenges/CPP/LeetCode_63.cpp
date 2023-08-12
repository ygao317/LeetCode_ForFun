class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        if (g[0][0] == 1 || g[m-1][n-1] == 1) return 0;
        g[0][0] = 1;
        for (int i = 1; i<m; ++i) g[i][0] = g[i][0] == 1 ? 0 : g[i-1][0];
        for (int j = 1; j<n; ++j) g[0][j] = g[0][j] == 1 ? 0 : g[0][j-1];
        for (int i=1; i<m; ++i)
            for (int j=1; j<n; ++j)
                g[i][j] = g[i][j] == 1 ? 0 : (g[i-1][j] + g[i][j-1]); 
        return g[m-1][n-1];
    }
};
