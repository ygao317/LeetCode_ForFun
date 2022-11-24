// 79. Word Search @ 2022/11/24

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size(), l = word.size();
        vector<int> dir={1,0,-1, 0, 1};
        
        function<bool(int, int, int)> dfs = [&] (int idx, int x, int y) {
            if (board[x][y] != word[idx]) return false; // out directly
            if (idx == l-1) return true; // reach the last item and matched
            board[x][y] = '0';
            for (int d=0; d<4; ++d){
                int xn = x + dir[d], yn = y + dir[d+1];
                if (xn<0 || xn == m || yn<0 || yn == n) continue;
                if (dfs(idx+1, xn, yn)) return true;
            }
            board[x][y] = word[idx];
            return false;
        };
        
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                if (dfs(0, i, j)) return true;

        return false;        
    }
};
