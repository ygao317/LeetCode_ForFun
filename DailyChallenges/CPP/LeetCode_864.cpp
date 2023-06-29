class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size(), l = 0; // 2^7 
        vector<int> start(3,0), d = {1,0,-1,0,1};
        for (int i=0; i<m; ++i){
            for (int j=0; j<n; ++j){
                if (grid[i][j] == '@') start = {i, j, 0};
                if (grid[i][j] >= 'a'&& grid[i][j] <= 'f') l |= 1<<(grid[i][j] - 'a'); 
            }
        }
        vector<vector<vector<int>>> v(m, vector<vector<int>>(n, vector<int>(l+1, 0))); // m * n * (l+1)
        queue<vector<int>> q; q.push(start); v[start[0]][start[1]][start[2]] = 1;
        int ans = 0;
        while (!q.empty()){
            ++ans;
            int sz = q.size();
            for (int i = 0; i< sz; ++i){
                auto st = q.front(); q.pop();
                for (int j = 0; j < 4; ++j){
                    int _x = st[0] + d[j], _y = st[1] + d[j+1];
                    if (_x < 0 || _x == m || _y < 0 || _y == n) continue; // out of boundary
                    if (v[_x][_y][st[2]]) continue;  // visited
                    if (grid[_x][_y] == '#') continue; // hit wall
                    
                    if (grid[_x][_y] >= 'A' && grid[_x][_y] <= 'F'){ // hit lock
                        if (st[2] & (1 << (grid[_x][_y]-'A'))){
                            q.push({_x, _y, st[2]});
                            v[_x][_y][st[2]] = 1;
                        }
                    }else if (grid[_x][_y] >= 'a' && grid[_x][_y] <= 'f'){ // hit key
                        int mask = st[2] | (1 << (grid[_x][_y]-'a'));
                        //cout << "found key: " << mask << "at " << _x << ", " << _y << endl; 
                        if (mask == l) return ans;
                        q.push({_x, _y, mask});
                        v[_x][_y][mask] = 1;
                    }else{ // pass through with '.' or '@'
                        q.push({_x, _y, st[2]});
                        v[_x][_y][st[2]] = 1;
                    }
                }
            }
            // cout << ans << " " << q.size() << endl;
        }
        return -1;
    }
};
