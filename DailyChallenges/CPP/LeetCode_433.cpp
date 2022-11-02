// 433. Minimum Genetic Mutation @ 2022/11/02

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bk(bank.begin(), bank.end());
        if (bk.find(end) == bk.end()) return -1;
        
        unordered_set<string> vt; vt.insert(start);
        
        int ans = 0;
        queue<string> q; q.push(start);
        while (!q.empty()){
            ans++;
            int sz = q.size();
            //cout << sz << " " << ans << endl;
            for (int i=0; i<sz; ++i){
                string s = q.front(); q.pop();
                for (int j=0; j<8; ++j){
                    for (auto& c: "ACGT"){
                        if (s[j] == c) continue;
                        string t = s; t[j] = c;
                        if (vt.find(t) != vt.end()) continue; // visited
                        if (bk.find(t) == bk.end()) continue; // not valid
                        if (t == end) return ans; // reach the end
                        q.push(t); // continue
                        vt.insert(t);
                    }
                }
            }
        }
        
        return -1;
    }
};
