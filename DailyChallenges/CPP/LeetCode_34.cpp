class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto itr = lower_bound(nums.begin(), nums.end(), target);
        if (itr == nums.end() || *itr != target) return {-1, -1};
        auto itr_r = upper_bound(itr, nums.end(), target);
        return {(int)distance(nums.begin(), itr), (int)distance(nums.begin(), itr_r)-1};
    }
};
