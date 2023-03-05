class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; ++i)
            m[arr[i]].push_back(i);

        queue<int> q; q.push(0);
        vector<bool> visited(n, false); visited[0] = true;
        
        int ans = 0;
        while (!q.empty()){
            int sz = q.size();
            for (int i = 0; i<sz; ++i){
                int idx = q.front(); q.pop();
                if (idx == n-1) return ans;
                if (idx > 0 && !visited[idx-1]) {
                    q.push(idx-1);
                    visited[idx-1] = true;
                }
                if (idx < n-1 && !visited[idx+1]){
                    q.push(idx+1);
                    visited[idx+1] = true;
                }
                for (auto _idx: m[arr[idx]]){
                    if (_idx != idx && !visited[_idx]){
                        q.push(_idx);
                        visited[_idx] = true;
                    }
                }
                m.erase(arr[idx]);
            }
            ans++;
        }
        return -1;
    }
};
