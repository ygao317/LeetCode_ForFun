class Solution {
private:
    int cnt_p[10] = {}, cnt_s[10002][10] = {};
    int pref[10][10] = {}, suff[10002][10][10] = {};    
public:
    int countPalindromes(string s) {
        int sz = s.size();
        for (int i = sz - 1; i>=0; --i) // count from right to left
            for (int n = 0; n < 10; ++n)
                cnt_s[i][n] = cnt_s[i + 1][n] + (s[i] == '0' + n);
        
        for(int i = sz - 2; i >= 0; --i) { // count for right to left on 2 digits pattern
            memcpy(suff[i], suff[i + 1], 100 * sizeof(int));
            for(int n1 = 0; n1 < 10; ++n1)
                suff[i][(s[i] - '0')][n1] += cnt_s[i + 1][n1];
        }
        
        long long res = 0;
        for (int i = 1; i < sz - 1; ++i)
            for(int n1 = 0; n1 < 10; ++n1) {
                for(int n2 = 0; n2 < 10; ++n2)
                    res = (res + (long long)pref[n1][n2] * suff[i + 1][n2][n1]) % 1000000007;
                cnt_p[n1] += s[i - 1] == '0' + n1; // count from left to right
                pref[n1][s[i] - '0'] += cnt_p[n1]; // count from left on 2 digits pattern
            }
        
        return res;
    }
};
