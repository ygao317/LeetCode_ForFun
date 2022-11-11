// 26. Remove Duplicates from Sorted Array @ 2022/11/11
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), i=0, j=0;
        for (; i<n && j<n; ++i, ++j){
            nums[i] = nums[j];
            while(j<n-1 && nums[j+1] == nums[j]) ++j;
        }
        return i;
    }
};
