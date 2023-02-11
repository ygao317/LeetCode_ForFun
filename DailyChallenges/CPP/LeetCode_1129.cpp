class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        unordered_map<int, vector<int>> m;
        for (auto &a: redEdges) m[a[0]].push_back(n+a[1]);
        for (auto &a: blueEdges) m[n+a[0]].push_back(a[1]);

        vector<int> ans(2* n, -1); ans[0] = 0; ans[n] = 0;
        queue<int> q; q.push(0); q.push(n);
        while (!q.empty()){
            int sz = q.size();
            for (int i=0; i<sz; ++i){
                int src = q.front(); q.pop();
                for (int des: m[src]){
                    if (ans[des] == -1){
                        ans[des] = ans[src]+1;
                        q.push(des);
                    }
                }
            }
        }

        for (int i=0; i<n; ++i){
            if (ans[i] == -1 || (ans[n+i] != -1 && ans[n+i] < ans[i]))
                ans[i] = ans[n+i];
        }
        ans.resize(n);
        return ans;
    }
};
