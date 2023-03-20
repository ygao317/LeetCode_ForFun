class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        vector<int> dir = {1, -2, 1, 2, -1, -2, -1, 2, 1};
        int n = grid.size();
        function<bool(int, int, int)> check = [&](int r, int c, int num){
            if (num == n*n-1) return true;
            bool found = false;
            int _r, _c;
            for (int d=0; d<8; ++d){
                _r = r + dir[d];
                _c = c + dir[d+1];
                if (_r >=0 && _r < n && _c >=0 && _c < n && grid[_r][_c] == num+1){
                    found = true;
                    break;
                }
            }
            if (found){
                //cout << _r << " " << _c << " " << num+1 << endl;
                return check(_r, _c, num+1);
            }else 
                return false;
        };
        return check(0, 0, 0);
    }
};
