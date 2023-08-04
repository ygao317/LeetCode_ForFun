class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> cache(s.size(), -1);
        function<bool(int)> dfs = [&](int p){
            if (p == s.size()) return true;
            if (cache[p] != -1) return bool(cache[p]);
            bool find = false;
            for (auto& w: wordDict){
                if (s.find(w, p) == p) find = dfs(p+w.size());
                if (find) return true;
            }
            return bool(cache[p] = find);
        };
        
        return dfs(0);
    }
};
