class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        auto updateGrid = [&](int st, int ed){
            if (st == ed) return;
            int i = min(st, ed), n = max(st, ed), c = (st<ed)? -1 : 0;
            for (; i < n; ++i)
                grid[cells[i][0]-1][cells[i][1]-1] = c;
        };

        vector<int> d = {1, 0, -1, 0, 1};
        auto bfs = [&](int t){ // bfs to check if possible
            queue<pair<int, int>> q;
            for (int y=0; y<col; ++y)
                if (grid[0][y] != -1){ q.push({0, y}); grid[0][y] = t;}
            
            while (!q.empty()){
                int sz = q.size();
                for (int i=0; i<sz; ++i){
                    auto [x, y] = q.front(); q.pop();
                    for (int j=0; j<4; ++j){
                        int _x = x + d[j], _y = y + d[j+1];
                        if (_x<0 || _x == row) continue;
                        if (_y<0 || _y == col) continue;
                        if (grid[_x][_y] == -1 || grid[_x][_y] == t) continue;
                        if (_x == row-1) return true;
                        q.push({_x, _y}); grid[_x][_y] = t;
                    } 
                }
            }
            return false;
        };

        // binary search
        int l = 0, r = row * col, m = 0;
        while (l < r){
            int _m = l + (r-l)/2;
            updateGrid(m, _m); m = _m;
            if (bfs(m)) l = m+1; else r = m;
        } 
        return l-1;
    }
};
