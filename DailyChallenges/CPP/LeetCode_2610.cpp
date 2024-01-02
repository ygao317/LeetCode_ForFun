class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> cnt(n+1, 0);
        for (auto num: nums){
            if (ans.size() == cnt[num]) ans.push_back({num});
            else ans[cnt[num]].push_back(num);
            ++cnt[num];
        }
        return ans;
    }
};
