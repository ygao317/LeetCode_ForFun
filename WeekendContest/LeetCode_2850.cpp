class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<vector<int>> as, bs;
        for (int i=0; i<3; ++i)
            for (int j=0; j<3; ++j)
                if (grid[i][j] == 0)
                    bs.push_back({i, j});
                else if (grid[i][j] > 1){
                    for (int k = 0; grid[i][j]-k > 1; ++k)
                        as.push_back({i, j});
                }
        
        //cout << as.size() << " " << bs.size() << endl;
        vector<int> visited(as.size(), 0);
        int ans = INT_MAX;
        function<void(int, int)> loop = [&](int i, int ls){
            if (i == as.size()) ans = min(ans, ls);
            else {
                for (int j = 0; j<bs.size(); ++j){
                    if (visited[j]) continue;
                    visited[j] = 1;
                    loop(i+1, ls + abs(as[i][0] - bs[j][0]) + abs(as[i][1] - bs[j][1]));
                    visited[j] = 0;
                }
            }
        };
        loop(0, 0);
        return ans;
    }
};
