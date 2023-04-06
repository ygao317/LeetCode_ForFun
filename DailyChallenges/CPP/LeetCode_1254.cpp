class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        function <int(int,int)> fill = [&](int i, int j){
            if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j])
                return 0;
            return (grid[i][j] = 1) + fill(i + 1, j) + fill(i, j + 1) 
        + fill(i - 1, j) + fill(i, j - 1);
        };

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (i * j == 0 || i == m - 1 || j == n - 1)
                    fill(i, j);
        
        int res = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                res += fill(i,j)>0;
        return res;
    }
};
