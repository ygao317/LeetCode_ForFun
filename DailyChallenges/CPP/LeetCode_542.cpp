class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> d = {1, 0, -1, 0, 1};
        queue<pair<int, int>> q;
        for (int i=0; i<m; ++i){
            for (int j=0; j<n; ++j){
                if (mat[i][j] == 0){
                    for (int k=0; k<4; ++k){
                        int x = i + d[k], y = j + d[k+1];
                        if (x<0 || x>=m || y<0 || y>= n) continue;
                        if (mat[x][y] != 0) q.push({x,y});
                    }
                } else mat[i][j] = -1;
            }
        }
        
        int dist = 1;
        while (!q.empty()){
            int sz = q.size();
            for (int i=0; i<sz; ++i){
                auto [x, y] = q.front(); q.pop();
                if (mat[x][y] != -1) continue;
                mat[x][y] = dist;
                for (int k=0; k<4; ++k){
                    int _x = x + d[k], _y = y + d[k+1];
                    if (_x<0 || _x>=m || _y<0 || _y>= n) continue;
                    if (mat[_x][_y] == -1) q.push({_x,_y});
                }
            }
            dist++;
        }

        return mat;
    }
};
