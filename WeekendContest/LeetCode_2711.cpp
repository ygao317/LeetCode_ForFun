class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        auto cnt = [&](int r, int c){
            set<int> s;
            vector<int> u;
            while(r < m && c < n){
                u.push_back(s.size()); 
                s.insert(grid[r++][c++]);
            }
            s.clear(); --r; --c;
            while(r >= 0 && c >= 0){
                int tmp = grid[r][c];
                grid[r--][c--] = abs((int)s.size() - u.back());
                u.pop_back();
                s.insert(tmp);
            }
        };
        for (int r = m-1; r >= 0; --r) cnt(r, 0);
        for (int c = 1; c < n; ++c) cnt(0, c);
        return grid;
    }
};
