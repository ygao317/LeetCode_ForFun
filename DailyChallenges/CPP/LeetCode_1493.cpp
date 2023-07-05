class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int c = 0, rc = 0, ans = 0;
        for (auto n: nums){
            if (n == 1){ c++; rc++; }
            else{
                ans = max(ans, rc);
                rc = c; c = 0;
            }
        }
        return (c == nums.size()) ? (c-1) : max(ans,rc);
    }
};
