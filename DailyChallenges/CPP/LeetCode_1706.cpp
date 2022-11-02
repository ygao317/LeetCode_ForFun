// 1706. Where Will the Ball Fall @ 2022/11/01

lass Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n, -1);
        
        for (int j = 0; j < n; ++j){
            ans[j] = j;
            for (int i = 0; i<m; ++i){
                if (grid[i][ans[j]] == 1){
                    if (ans[j] == n-1 || grid[i][ans[j]+1] == -1){
                        ans[j] = -1; break;
                    }
                    ans[j] = ans[j]+1;
                }else{
                    if (ans[j] == 0 || grid[i][ans[j]-1] == 1){
                        ans[j] = -1; break;
                    }
                    ans[j] = ans[j]-1;
                }
            }
        }
        
        return ans;
    }
};
