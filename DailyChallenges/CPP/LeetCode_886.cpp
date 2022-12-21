class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        map<int, vector<int>> m;
        for (auto& e: dislikes)
            m[e[0]].push_back(e[1]),m[e[1]].push_back(e[0]);

        vector<int> cols(n+1, 0);
        for (int i=1; i<n+1; i++){
            if (cols[i] != 0 || m[i].empty()) continue;
            queue<int> q; q.push(i);
            int c = 1; cols[i] = c;
            while (!q.empty()){
                int sz = q.size(); c = -c;
                for (int j=0; j<sz; j++){
                    int l = q.front(); q.pop(); 
                    for (auto dl: m[l]){
                        if (cols[dl] == cols[l]) return false;
                        if (cols[dl] == 0)
                            cols[dl] = c, q.push(dl);
                    }
                }
            }
        }

        return true;
    }
};
