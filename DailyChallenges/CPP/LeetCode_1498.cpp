class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int mod = 1e9+7, n = nums.size();
        vector<int> pows(n,1); // do the precomputation
        for (int i=1; i<n; ++i)
            pows[i] = pows[i-1] * 2 % mod;
        
        int l = 0, r = n-1, res = 0;
        while (l <= r) { // take l, others eith choose or not 
            if (nums[l] + nums[r] > target) 
                r--;
            else
                res = (res + pows[r - l++]) % mod;
        }
        return res;
    }
};
