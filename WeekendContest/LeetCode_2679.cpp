class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for (auto & ns: nums)
            sort(ns.begin(), ns.end());
        int ans = 0;
        for (int i=0; i<nums[0].size(); ++i){
            int m = 0;
            for (auto & ns: nums)
                m = max(m, ns[i]);
            ans += m;
        }
        return ans;
    }
};
