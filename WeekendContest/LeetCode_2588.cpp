class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long ans = 0, pre = 0;
        unordered_map<int, int> dp; dp[0] = 1;
        for (int num: nums)
            ans += dp[pre ^= num]++;
        return ans; 
    }
};
