class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        function<int(int, int)> fish = [&](int r, int c){
            int t = grid[r][c];
            grid[r][c] = 0;
            if (r+1 < m && grid[r+1][c]>0) t += fish(r+1, c);
            if (r-1 >= 0 && grid[r-1][c]>0) t += fish(r-1, c);
            if (c+1 < n && grid[r][c+1]>0) t += fish(r, c+1);
            if (c-1 >= 0 && grid[r][c-1]>0) t += fish(r, c-1);
            return t;
        };

        int ans = 0;
        for (int r=0; r<m; ++r)
            for (int c=0; c<n; ++c)
                if (grid[r][c]>0)
                    ans = max(ans, fish(r,c));
                
        return ans;
    }
};
