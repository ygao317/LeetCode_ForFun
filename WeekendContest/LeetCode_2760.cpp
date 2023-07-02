class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans = 0, l = -1;
        for (int i = 0; i<nums.size(); ++i){
            if (l != -1){
                if (nums[i] % 2 != nums[i - 1] % 2 && nums[i] <= threshold) continue;
                ans = max(ans, i-l); l = -1;
            }
            if (nums[i] % 2 == 0 && nums[i] <= threshold) l = i;
        }
        return (l == -1) ? ans : max(ans, (int)nums.size() - l);
    }
};
