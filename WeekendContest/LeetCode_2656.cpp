class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        return (*max_element(nums.begin(), nums.end()) * 2 + k - 1) * k /2;
    }
};
