class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;

        function<bool(int, int)> isPal = [&](int i, int j) { return (i<j)? (s[i] == s[j] && isPal(i+1,j-1)) : true; };
        
        function<void(vector<string>&, int)> dfs = [&](vector<string>& v, int i){
            if (i == n){
                ans.push_back(v); 
                return;
            }
            for (int j = i; j < n; ++j){
                if (isPal(i,j)){
                    v.push_back(s.substr(i, j-i+1));
                    dfs(v, j+1);
                    v.pop_back();
                }
            }
        };
        vector<string> v;
        dfs(v, 0);
        return ans;
    }
};
