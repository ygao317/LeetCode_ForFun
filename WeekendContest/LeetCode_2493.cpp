class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> m;
        for (auto& v: edges)
            m[v[0]].push_back(v[1]), m[v[1]].push_back(v[0]);
        
        int ans = 0;
        vector<int> record(n+1, 0);
        for (int i = 1; i<=n; ++i){
            if (record[i] > 0) continue; // done the sub loop
            int lmax = 1;
            deque<int> dq; dq.push_back(i); record[i] = i;
            // do the first BST
            while (!dq.empty()){
                deque<int> dqn;
                while (!dq.empty()){
                    int p = dq.front(); dq.pop_front();
                    for (auto& ch: m[p]){
                        if (record[ch] == i){ // visit already
                            if (find(dq.begin(), dq.end(), ch) != dq.end()) return -1;  // find odd number loop
                        }else 
                            dqn.push_back(ch), record[ch] = i;
                    }
                }
                if (!dqn.empty()) ++lmax;
                dqn.swap(dq);
            }
            // do the other BST
            for (int l = i+1; l<=n; ++l){
                if (record[l] != i) continue;
                int llm = 1;
                unordered_set<int> seen; seen.insert(l);
                queue<int> q; q.push(l); 
                while (!q.empty()){
                    int n = q.size();
                    for (int j = 0; j < n; ++j){
                        int p = q.front(); q.pop();
                        for (auto ch: m[p])
                            if (seen.find(ch) == seen.end())
                                q.push(ch), seen.insert(ch);
                    }
                    if (!q.empty()) ++llm;
                }
                lmax = max(llm, lmax);
            }
            ans += lmax;
        }
        return ans;
    }
};
