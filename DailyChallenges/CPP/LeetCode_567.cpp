class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int cnt[26] = {0};
        for(auto ch: s1)
            cnt[ch - 'a']++;

        int l = 0, r = 0;
        while(r < s2.size()){
            cnt[s2[r] - 'a']--;
            while(cnt[s2[r] - 'a'] < 0){
                cnt[s2[l] - 'a']++;
                l++;
            }
            if(r - l + 1 == s1.size()) {
                return true;
            }
            r++;
        }
        return false;
    };
};
