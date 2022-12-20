class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
       int n = rooms.size();
       vector<bool> visited(n, false); visited[0] = true;
       queue<int> q; q.push(0);
       while (!q.empty()){
           int sz = q.size();
           for (int i = 0; i < sz; ++i){
               int r = q.front(); q.pop();
               for (auto k: rooms[r]){
                   if (!visited[k]){
                       visited[k] = true;
                       q.push(k);
                   }
               }
           }
       }
       return all_of(visited.begin(), visited.end(), [](bool v) { return v; });
    }
};
