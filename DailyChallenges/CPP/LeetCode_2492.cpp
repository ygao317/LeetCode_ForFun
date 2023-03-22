class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int,int>>> m;
        for (const auto& r:roads){
            m[r[0]].push_back({r[1], r[2]});
            m[r[1]].push_back({r[0], r[2]});
        }

        int ans = INT_MAX;
        vector<bool> visited(n,false); visited[0] = true;
        queue<int> q; q.push(1); 
        while (!q.empty()){
            int n = q.size();
            for (int i=0; i<n; ++i){
                int p = q.front(); q.pop();
                for (auto [child, dist]: m[p]){
                    ans = min(ans,dist); // even visited, update the distance
                    if (!visited[child-1]){
                        q.push(child);
                        visited[child-1] = true;
                    }
                }
            }
        }
        
        return ans;
    }
};
