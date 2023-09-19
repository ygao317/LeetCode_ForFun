class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // same as find the start of cycle.
        int s = nums[0], f= s;
        do {
            s = nums[s]; f = nums[nums[f]];
        } while (s != f);

        int r = nums[0];
        while (s != r) {
            s = nums[s]; r = nums[r];
        }

        return r; 
    }
};
