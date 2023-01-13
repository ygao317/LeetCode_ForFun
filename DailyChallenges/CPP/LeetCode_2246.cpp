class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();

        unordered_map<int, vector<int>> m; 
        for (int i = 1;i < n; ++i)
            m[parent[i]].push_back(i);

        int ans = 1;
        queue<int> q; q.push(0);
        
        function<int(int)> dfs = [&](int node) {
            if (m[node].size() == 0) return 1; // reach the end
            vector<int> chLen;
            for (int child: m[node]){
                if (s[child] == s[node])
                    q.push(child);
                else 
                    chLen.push_back(dfs(child));
            }
            int cl_n = chLen.size();
            if (cl_n > 1){
                nth_element(chLen.begin(), chLen.end()-2, chLen.end());
                ans = max(ans, chLen[cl_n-1] + chLen[cl_n-2] + 1);
                return chLen[cl_n-1] + 1;
            }else if (cl_n == 1){
                ans = max(ans, chLen[0] + 1);
                return chLen[0] + 1;
            }else
                return 1;
        };
        
        while (!q.empty()){
            int node = q.front(); q.pop();
            dfs(node);
        }

        return ans;
    }
};
