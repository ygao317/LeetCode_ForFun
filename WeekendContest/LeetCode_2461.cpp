// 2461. Maximum Sum of Distinct Subarrays With Length K

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        long long lm = 0, ans = 0;
        for (int i=0; i<nums.size(); ++i){
            ++m[nums[i]];
            lm += nums[i];
            if (i>=k){
                --m[nums[i-k]];
                if (!m[nums[i-k]]) m.erase(nums[i-k]);
                lm -= nums[i-k];
            }
            if (m.size() == k) ans = max(ans, lm);
        }
        return ans;
    }
};
