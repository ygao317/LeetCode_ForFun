class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {

        unordered_map<int, vector<int>> m_st, m_ed;
        for (auto & a: connections){
            m_st[a[0]].push_back(a[1]);
            m_ed[a[1]].push_back(a[0]);
        } 

        int ans = 0;
        queue<int> q; q.push(0);
        vector<int> visited(n, 0); visited[0] = 1;

        while (!q.empty()){
            int sz = q.size();
            for (int i = 0; i<sz; ++i){
                int node = q.front(); q.pop();
                for (int st: m_ed[node]){ q.push(st); visited[st] = 1;}
                for (int ed: m_st[node]){
                    if (!visited[ed]){
                        ans++; q.push(ed); visited[ed] =1;
                    }
                }
            }
        }

        return ans;
    }
};
