// 2131. Longest Palindrome by Concatenating Two Letter Words @20221103

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        unordered_map<string, int> m;
        
        for (auto & w: words){
            string rw = w; 
            reverse(rw.begin(), rw.end());
            if (m[rw]>0){
                --m[rw]; 
                ans += 4;
            }else 
                ++m[w];
        }
        
        // as "dd" has gone through the reverse check as well, so if has, the v either 1 or 0
        for (auto& [k, v]: m){ 
            if (k[0] == k[1] && v > 0) return ans + 2;
        }
        
        return ans;
    }
};
