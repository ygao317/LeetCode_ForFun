class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0; int r = nums.size();
        
        while(l < r)
        {
            int m = l + (r-l) / 2;
            if (nums[m] == target) return true;
			if((nums[l] == nums[m]) && (nums[r-1] == nums[m])){
                l++; r--;
            } else if(nums[l] <= nums[m]) { // left
                if((nums[l] <= target) && (nums[m] > target)) r = m; else l = m + 1;
            } else { // right
                if((nums[m] < target) && (nums[r-1]>= target)) l = m + 1; else r = m;
            }
        }
        
        return false;
    }
};
