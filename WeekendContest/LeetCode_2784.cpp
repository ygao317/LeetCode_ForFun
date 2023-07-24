class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n,0);
        for (int i = 0; i<n; ++i){
            if (nums[i] > n-1) return false;
            ++v[nums[i]];
            if (nums[i] != n-1 && v[nums[i]]>1) return false;
        }
        return true;
    }
};
