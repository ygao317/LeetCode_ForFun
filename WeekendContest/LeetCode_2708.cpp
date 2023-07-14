class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long ans = 1; int nc = 0, pc = 0;
        for (int num: nums){
            if (num == 0) continue;
            if (num < 0) ++nc; else ++pc;
            ans *= num;
        }
        if (pc > 0 || nc>1)
            return (nc % 2 == 0)? ans : (ans / nums[nc-1]);
        else
            return nums.back();
    }
};
