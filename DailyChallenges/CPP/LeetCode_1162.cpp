class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<int> q;
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                if (grid[i][j] == 1)
                    q.push(i * 100 + j);

        if (q.empty()) return -1; // all water

        int dir[5] = {1, 0, -1, 0, 1};
        int steps = 0;
        while (!q.empty()){
            ++steps;
            int sz = q.size();
            for (int k = 0; k < sz; ++k){
                int i = q.front() / 100, j = q.front() % 100; q.pop();
                for (int k = 0; k<4; ++k){
                    int _i = i + dir[k], _j = j + dir[k+1];
                    if (_i>=0 && _i<n && _j>=0 && _j<n && grid[_i][_j] == 0){
                        grid[_i][_j] = steps;
                        q.push(_i * 100 + _j);
                    }
                }
            }
        }
        return (steps == 1) ? -1 : (steps-1);
    }
};
