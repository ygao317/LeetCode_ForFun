class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> ans(nums.size(), 0);
        int mx = nums[0];
        for (int i=0; i<nums.size(); ++i){
            mx = max(mx, nums[i]);
            ans[i] = ((i==0)?0LL:ans[i-1]) + mx + nums[i];
        }
        return ans;
    }
};
