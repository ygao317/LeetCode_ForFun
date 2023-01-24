class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), ans = 0;
        vector<int> visited(n*n+1); visited[1] = true;
        queue<int> q; q.push(1);
        while (!q.empty()){
            ans++;
            int sz = q.size();
            for (int i = 0; i<sz; ++i){
                int st = q.front(); q.pop();
                for (int ed = st+1; ed <= st+6 && ed <= n*n; ++ed){
                    if (visited[ed]) continue;
                    int r = (ed-1) / n, c = (ed-1) % n;
                    c = (r%2 == 0)?c:(n-c-1); r = n-1-r;
                    if (board[r][c] != -1) 
                        q.push(board[r][c]);
                    else
                        q.push(ed);
                    if (q.back() == n*n) return ans;
                    visited[ed] = true;
                }
            }
        }
        return -1;
    }
};
