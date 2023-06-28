class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int, vector<pair<int, double>>> es;
        for (int i=0; i<edges.size(); ++i){
            es[edges[i][0]].push_back({edges[i][1], succProb[i]});
            es[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double> v(n, 0.); v[start] = 1.;
        queue<int> q; q.push(start);
        while (!q.empty()){
            int sz = q.size();
            for (int i=0; i<sz; ++i){
                int st = q.front(); q.pop();
                for (auto& [ed, p]: es[st]){
                    if (v[ed] >= v[st] * p) continue;
                    v[ed] = v[st] * p;
                    if (ed == end) continue;
                    q.push(ed);
                }
            }
        }
        return v[end];
    }
};
