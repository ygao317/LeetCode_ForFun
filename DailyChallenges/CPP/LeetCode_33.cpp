class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size(), n = nums.size();
        while (l < r){
            int m = l + (r-l)/2;
            if (nums[m] > nums[n-1]) l = m+1; else r = m;
        }
        if (target >= nums[0]){ // left
            auto itr = lower_bound(nums.begin(),nums.begin()+l, target);
            if (*itr == target) return itr - nums.begin();
        }
        if (target <= nums[n-1]){ // right
            auto itr = lower_bound(nums.begin()+l,nums.end(), target);
            if (*itr == target) return itr - nums.begin();
        }
        return -1;
    }
};
