class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size();
        while (l+1 < r){
            int m = (l+r)/2;
            if (m%2 == 0 && nums[m] == nums[m+1]) // at the second half
                l = m;
            else if (m%2 == 1 && nums[m-1] == nums[m]) // at the second half
                l = m+1;
            else {
                r = (m%2 == 0) ? (m+1) : m;
            }
        }
        return nums[l];
    }
};
