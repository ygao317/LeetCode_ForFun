// 2466. Count Ways To Build Good Strings

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long> v(high+1, 0L); v[zero] += 1; v[one] += 1;
        long ans=0, mod = 1e9+7;
        for (int i=0; i<high+1; ++i){
            v[i] = (v[i] + ((i-zero > 0)? v[i-zero]: 0) + ((i-one > 0)? v[i-one]: 0)) % mod;
            if (i>= low)
                ans = (ans + v[i]) % mod;
        }
        return ans;
    }
};
