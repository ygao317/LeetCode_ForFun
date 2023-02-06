class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (m + n <=3) return false;
        
        grid[m-1][n-1] = -1;
        function<bool(int, int)> dfs = [&](int i, int j){
            if (i >=m || j >=n) return false;
            if (grid[i][j] == -1) return true;
            bool inPath = false;
            if (i < m-1 && grid[i+1][j] != 0) // can go down
                inPath = dfs(i+1, j);
            if (j < n-1 && grid[i][j+1] != 0) // can go right
                inPath = dfs(i, j+1) || inPath;
            if (inPath) grid[i][j] = -1;
            return inPath;
        };
        bool inPath = dfs(0, 0);
        if (!inPath) return true; // No path at all

        function<bool(int, int)> d_cnt = [&](int i, int j){
            int cnt = (grid[i][j] == -1) ? 1 : 0;
            while (!(j == 0 || i == m-1)){
                j = (j + n - 1) % n; i++;
                cnt += (grid[i][j] == -1) ? 1 : 0;
            }
            return cnt == 1;
        };

        for (int j = 1; j < n; ++j)
            if (d_cnt(0, j)) 
                return true;

        for (int i = 1; i < m-1; ++i)
            if (d_cnt(i, n-1)) 
                return true;

        return false;
    }
};
