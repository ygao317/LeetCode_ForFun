class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> m(26,0);
        iota(m.begin(), m.end(), 1);
        for (int i=0; i< chars.size(); ++i) m[(chars[i]-'a')] = vals[i];
        
        int ans = 0, lc = 0;
        for (int ch:s){
            lc += m[ch-'a'];
            ans = max(ans, lc);
            if (lc < 0) lc = 0;
        }
        
        return ans;
    }
};
