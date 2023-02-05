class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int cnt[26]= {0};
        for (auto ch: p)
            ++cnt[ch - 'a'];
        
        vector<int> ans;
        int l = 0, r = 0;
        while (r < s.size()){
            --cnt[s[r]-'a'];
            while (cnt[s[r]-'a'] < 0) {
                ++cnt[s[l++]-'a'];
            }
            if (r-l+1 == p.size()) 
                ans.push_back(l);
            ++r;
        }
        return ans;
    }
};
