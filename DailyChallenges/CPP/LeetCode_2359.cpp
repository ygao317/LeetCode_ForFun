class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        if (node1 == node2) return node1;
        int n = edges.size();
        vector<int> v(n); v[node1] = 1; v[node2] = -1;
        queue<int> q; q.push(node1); q.push(node2);
        while (!q.empty()){
            set<int> s;
            int sz = q.size();
            for (int i = 0; i<sz; ++i){
                int st = q.front(); q.pop();
                int ed = edges[st]; 
                if (ed == -1) continue;
                if (v[ed] == -v[st]) 
                    s.insert(ed);
                else if (v[ed] == v[st]) 
                    continue;
                else{
                    v[ed] = v[st]; q.push(ed);
                }
            }
            if (!s.empty()) return *s.begin();
        }
        return -1;
    }
};
