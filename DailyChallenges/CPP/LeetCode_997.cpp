class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<bool> t(n+1); 
        unordered_map<int, unordered_set<int>> m;
        for (auto& a: trust){
            t[a[0]] = true;
            if (!t[a[1]])
                m[a[1]].insert(a[0]);
        }
        int cnt = 0, judge = 0;
        for (int i = 1; i<=n; ++i){
            if (!t[i] && m[i].size() == n-1){
                ++cnt; 
                judge = i;
            }
        }
        return (cnt == 1) ? judge : -1;
    }
};
