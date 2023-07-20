class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int l = 0, m = 0, r = 1, ans = 0;
        for (; r < s.size(); ++r){
            if (s[r] == s[r-1]){
                ans = max(ans, r-l);
                l = m; 
                m = r;
            }
        }
        ans = max(ans, r-l);
        return ans;
    }
};
