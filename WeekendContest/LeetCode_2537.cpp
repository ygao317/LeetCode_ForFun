class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        // sliding window
        unordered_map<int, int> cnts;
        long long ans = 0L;
        int pairs = 0, i = 0, j = 0, n = nums.size();
        for (; i<n; ++i){
            if (i>0){ // move out of window
                pairs -= --cnts[nums[i-1]];
                if (cnts[nums[i-1]] == 0) cnts.erase(nums[i-1]);
            }
            for (; j<nums.size() && pairs<k; ++j){ // move in the window
                pairs += cnts[nums[j]]++;
            }
            ans += (n-j) + (pairs>=k);
        }
        return ans;
    }
};
