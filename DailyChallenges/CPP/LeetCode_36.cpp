// 36. Valid Sudoku @2022/11/23

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        auto isValid = [](vector<char>& a){
            vector<int> freq(9, 0);
            for (auto& ch:a){
                if (ch == '.') continue;
                if (++freq[ch-'1']>1) return false;
            }
            return true;
        };
        
        // row first
        for (int i=0; i<9; ++i)
            if (!isValid(board[i])) return false;
        
        // col first
        for (int j=0; j<9; ++j){
            vector<char> chs(9);
            for (int i=0; i<9; ++i)
                chs[i] = board[i][j];
            if (!isValid(chs)) return false;
        }
        
        // small square
        for (int i=0; i<9; i+=3){
            for (int j=0; j<9; j+=3){
                vector<char> chs;
                chs.push_back(board[i][j]),chs.push_back(board[i][j+1]),chs.push_back(board[i][j+2]);
                chs.push_back(board[i+1][j]),chs.push_back(board[i+1][j+1]),chs.push_back(board[i+1][j+2]);
                chs.push_back(board[i+2][j]),chs.push_back(board[i+2][j+1]),chs.push_back(board[i+2][j+2]);
                if (!isValid(chs)) return false;
            }
        }
        
        return true;
    }
};
