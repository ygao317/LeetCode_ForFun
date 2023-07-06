class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX, l = 0, ls = 0;
        for (int i = 0; i< nums.size(); ++i){
            ls += nums[i];
            while (ls - nums[l] >= target)
                ls -= nums[l++];
            if (ls >= target) ans = min(ans, i-l+1);
        }
        return (ans == INT_MAX) ? 0 : ans;
    }
};
