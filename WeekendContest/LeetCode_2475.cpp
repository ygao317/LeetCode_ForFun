// 2475. Number of Unequal Triplets in Array

class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int n : nums)
            ++m[n];
        int res = 0, left = 0, right = nums.size();
        for (auto [_, cnt] : m) {
            right -= cnt;
            res += left * cnt * right;
            left += cnt;
        }
        return res;
    }
};
