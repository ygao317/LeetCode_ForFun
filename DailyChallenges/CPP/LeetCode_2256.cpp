// 2256. Minimum Average Difference @ 2022/12/04

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> preSum(n, 0L); preSum[0] = nums[0];
        for (int i=1; i<n; ++i)
            preSum[i] = preSum[i-1] + nums[i];
        
        int ans = -1, diff = INT_MAX;
        for (int i=0; i<n; ++i){
            int ld = abs(preSum[i]/(i+1)-((i == n-1)? 0 : (preSum[n-1]-preSum[i])/(n-i-1)));
            if (ld < diff)
                diff = ld, ans = i;
        }
        
        return ans;
    }
};
