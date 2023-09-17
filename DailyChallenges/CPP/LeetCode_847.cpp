class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n==1) return 0;

        int finalMask = (1<<n)-1;
        vector<vector<bool>> visited(n, vector<bool>(finalMask, false));

        queue<pair<int, int>> q; 
        for(int i=0 ; i<n ; i++) q.push({i,1<<i});

        int shortestPath = 0;
        while(!q.empty()){
            shortestPath++;
            int l = q.size();
            while(l--){
                auto [currState, currMask] = q.front(); q.pop();
                for(auto &adjNode: graph[currState]){
                    int nextMask = currMask | 1<< adjNode;
                    if(nextMask == finalMask) return shortestPath;
                    if(!visited[adjNode][nextMask]){
                        visited[adjNode][nextMask] = true;
                        q.push({adjNode, nextMask});
                    }
                }
            }
        }

        return -1;
    }
};
