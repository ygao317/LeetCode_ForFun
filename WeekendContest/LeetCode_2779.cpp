class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lc = 1, l = 0;
        for (int i = 1; i < nums.size(); ++i){
            while (nums[i] - nums[l] > 2 * k) ++l;
            lc = max(lc, i-l+1);
        }
        return lc;
    }
};
