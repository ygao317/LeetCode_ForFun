// 2470. Number of Subarrays With LCM Equal to K

class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        for (int i=0; i<n; ++i){
            int lm = nums[i];
            for (int j=i; j<n; ++j){
                lm = lcm(lm, nums[j]);
                if (lm>k) break;
                ans += (lm == k);
            }
        }
        return ans;
    }
};
