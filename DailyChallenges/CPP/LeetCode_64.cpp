class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(); 
        vector<vector<int>> memo(m, vector<int>(n, INT_MAX));
        vector<int> d = {1, 0, 1};
        
        function<void(int, int, int)> dfs = [&](int x, int y, int ls) {
            if (x > m-1 || y > n-1) return;
            int _ls = ls + grid[x][y];
            if (_ls >= memo[x][y]) return; else memo[x][y] = _ls;
            for (int i = 0; i<2; ++i)
                dfs(x + d[i], y + d[i+1], _ls);
        };
        dfs(0, 0, 0);
        
        return memo[m-1][n-1];
    }
};
