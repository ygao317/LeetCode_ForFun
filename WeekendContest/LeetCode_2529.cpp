class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto itr_l = lower_bound(begin(nums), end(nums), 0);
        auto itr_r = upper_bound(begin(nums), end(nums), 0);
        return max(itr_l - begin(nums), end(nums) - itr_r);
    }
};
