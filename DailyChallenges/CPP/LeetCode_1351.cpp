class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i=0; i < m; ++i){
            for (int j=0; j < n; ++j){
                if (grid[i][j] < 0){
                    ans += (m-i) * (n-j);
                    n = j;
                }
            }
            if (n == 0) break;
        }
        return ans;
    }
};
