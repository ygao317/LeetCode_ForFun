class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for (auto n: nums) k ^= n;
        return __builtin_popcount(k);
    }
};
