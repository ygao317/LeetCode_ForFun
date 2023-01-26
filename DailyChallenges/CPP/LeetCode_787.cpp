class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> m;
        for (auto & e: flights)
            m[e[0]].push_back({e[1], e[2]});
        vector<int> visited(n, INT_MAX); visited[src] = 0;
        queue<int> q; q.push(src);
        int cnt = 0;
        while (!q.empty() && cnt <= k){
            ++cnt;
            int sz = q.size();
            unordered_map<int, int> tm;
            for (int i=0; i<sz; ++i){
                int st = q.front(); q.pop();
                for (auto ed: m[st]){
                    int cost = visited[st] + ed.second;
                    if (cost < visited[ed.first]){
                        if (tm[ed.first] == 0 || tm[ed.first] > cost)
                            tm[ed.first] = cost;
                    }
                }
            }
            for (auto [k, v]: tm){
                visited[k] = v; q.push(k);
            }
        }
        for (auto cost: visited)
            cout << cost << " ";
        return (visited[dst] == INT_MAX) ? -1 :  visited[dst];
        
    }
};
