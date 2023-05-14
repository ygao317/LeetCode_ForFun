class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        //auto bitlen = [](int x) { return 32 - __builtin_clz(x); }
        int n = nums.size();
        vector<int> pref(n+1, 0), suff(n+1, 0);
        for (int i=0; i<n; ++i){
            pref[i+1] = pref[i] | nums[i];
            suff[i+1] = suff[i] | nums[n-1-i];
        }
        
        long long ans = 0;
        for (int i=0; i<n; ++i)
            ans = max(ans, (long long)nums[i] << k | pref[i] | suff[n-1-i]);

        return ans;
    }
};
