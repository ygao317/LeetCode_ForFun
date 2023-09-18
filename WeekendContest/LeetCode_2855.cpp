class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int c = 0, ans = 0, n = nums.size();
        for (int i = 1; i<n; ++i)
            if (nums[i] < nums[i-1]){ // need to shift
                ++c; ans = n-i;
                if (c>1 || nums[0]< nums[n-1]) return -1;
            }
                
        return ans;
    }
};
