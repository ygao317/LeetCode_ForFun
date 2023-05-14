class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ns(n); // {parent, edges}
        for (int i=0; i<n; ++i) ns[i] = {i, 0};
        
        function<int(int)> find = [&](int i) { 
            int p = ns[i][0]; 
            return (p == i)?  i : (ns[i][0] = find(p)); 
        };
        
        for (auto &e: edges){
            ++ns[e[0]][1]; ++ns[e[1]][1];
            int p0 = find(e[0]); int p1 = find(e[1]);
            if (p0 != p1) ns[p0][0] = p1;
        }

        unordered_map<int, pair<int, int>> cnt; // parent -> {nodes count, edges count}
        for (auto &nd: ns){
            int p = find(nd[0]);
            ++cnt[p].first;
            cnt[p].second += nd[1];
        }

        int ans = 0;
        for (auto& [_, ct]: cnt)
            if (ct.second == ct.first * (ct.first-1)) ++ans;
        
        return ans;
    }
};
