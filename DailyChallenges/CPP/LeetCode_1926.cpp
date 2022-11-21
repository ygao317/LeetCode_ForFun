// 1926. Nearest Exit from Entrance in Maze @ 2022/11/21

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size(), ans = 0;
        vector<int> dir = {1, 0, -1, 0, 1};
        queue<vector<int>> q;
        q.push(entrance); maze[entrance[0]][entrance[1]] = '+';
        
        while (!q.empty()){
            ++ans;
            int sz = q.size();
            for (int i=0; i<sz; ++i){
                vector<int> st = q.front(), ed(2); q.pop();
                for (int d = 0; d<4; ++d){
                    ed[0] = st[0]+dir[d]; ed[1] = st[1]+dir[d+1];
                    if (ed[0]<0 || ed[0]>=m || ed[1]<0 || ed[1]>=n || maze[ed[0]][ed[1]] == '+') continue;
                    if (ed[0]==0 || ed[0] == m-1 || ed[1] == 0 || ed[1] == n-1) return ans; 
                    q.push(ed); maze[ed[0]][ed[1]] = '+';
                }
            }
        }
        return -1;
    }
};
