class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size(), ans = -1;
        auto md = [](int x){
            int digit = 0;
            while (x>0){
                digit = max(digit, x%10);
                x /= 10;
            }
            return digit;
        };
        for (int i = 0; i<n-1; ++i){
            int x = md(nums[i]);
            for (int j = i+1; j<n; ++j)
                if (md(nums[j]) == x) 
                    ans = max(ans, nums[i]+nums[j]);
        }
        return ans;
    }
};
