// 2460. Apply Operations to an Array

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n-1; ++i){
            if (nums[i] == nums[i+1]){
                nums[i] += nums[i];
                nums[i+1] = 0;
            }
        }
        
        int i=0, j=0;
        while (j < n){
            while(i<n && nums[i] != 0) ++i; // find first 0
            j = i+1;
            while(j<n && nums[j] == 0) ++j; // find first non 0
            if (j<n)
                swap(nums[i++], nums[j++]);
        }
            
        return nums;
    }
};
