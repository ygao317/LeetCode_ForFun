class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int zeros = 0, ones = 0, ans = 0;
        for (int i=0; i< s.size(); ++i){
            if (s[i] == '0'){
                if (ones > 0) {
                    ans = max(ans, min(ones, zeros)*2);
                    ones = 0;
                    zeros = 0;
                }
                zeros += 1; 
            }else{
                ones += 1;
            }
        }
        return max(ans, min(ones, zeros)*2);
    }
};
