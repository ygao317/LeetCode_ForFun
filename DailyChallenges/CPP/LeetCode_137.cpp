class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size()/3;
        while (l<r){
            int m = l + (r-l)/2;
            if (nums[3*m] == nums[3*m+1]) l = m+1; else r = m;
        }
        return nums[3*r];
    }
};
