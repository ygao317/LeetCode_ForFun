class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size(), i1 = -1, in = -1;
        for (int i=0; i<n; ++i){
            if (nums[i] == 1) i1 = i;
            if (nums[i] == n) in = i;
        }
        return i1 + (n-1-in) - ((i1<in)?0:1);
    }
};
