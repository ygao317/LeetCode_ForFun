class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, dp0 = 1, dp1 = 0;
        for (int num: nums){
            if (num == 0){
                dp1 += 1;
                dp0 += dp1-1;
            } else {
                ans += dp0 + dp1 -1;
                dp0 = 1;
                dp1 = 0;
            }
        } 
        return ans + dp0 + dp1 - 1;
    }
};
