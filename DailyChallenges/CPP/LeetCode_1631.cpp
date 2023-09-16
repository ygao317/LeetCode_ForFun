class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        if (m==1 && n ==1) return 0;
        vector<int> dir = {0, -1, 0, 1, 0};
        auto bfs = [&](int diff){
            queue<pair<int,int>> q; q.push({0,0});
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            visited[0][0] = true;
            while (!q.empty()){
                int sz = q.size();
                for (int i=0; i<sz; ++i){
                    auto [x, y] = q.front(); q.pop();
                    for (int j=0; j<4; j++){
                        int _x = x + dir[j], _y = y + dir[j+1];
                        if (_x<0 || _x>=m || _y<0 || _y>=n || 
                            visited[_x][_y] || abs(heights[x][y]-heights[_x][_y])>diff) continue;
                        if (_x == m-1 && _y == n-1) return true;
                        visited[_x][_y] = true;
                        q.push({_x,_y});
                    }
                }
            }
            return false;
        };

        int l = 0, r= 1e6;
        while (l<r){
            int m = l + (r-l)/2;
            if (bfs(m)) r = m; else l=m+1;
        }
        return l;
    }
};
