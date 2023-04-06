class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans; ans.push_back({nums[0]});
        int sz = 1, r = 1;
        for (int i= 1; i<nums.size(); ++i){
            if (nums[i] != nums[i-1]) r = 0;
            if (r == sz){
                ans.push_back({nums[i]});
                sz++; r++;
            }else{
                ans[r++].push_back(nums[i]);
            }
        }
        return ans;
    }
};
