class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto itr = lower_bound(nums.begin(), nums.end(), target);
        return (itr != nums.end() && *itr == target) ? (itr - nums.begin()) : -1;
    }
};
