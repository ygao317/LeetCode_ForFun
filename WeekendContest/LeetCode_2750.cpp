class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        // moving pointers
        int zc = 0, oc = 0;
        long long ans = 0, k = 1e9 + 7;
        for (auto n: nums){
            if (n == 1){
                ++oc;
                if (oc == 1) ans = 1; else ans = ans * (zc + 1) % k;
                zc = 0;
            } else ++zc;
        }
        return ans;
    }
};
