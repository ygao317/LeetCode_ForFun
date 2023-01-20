class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> s;
        function<void(int, vector<int>&)> dfs = [&] (int i, vector<int>& v) {
            if (i>=n) return;
            if (nums[i] >= v.back()){
                v.push_back(nums[i]);
                s.insert(v);
                dfs(i+1, v);
                v.pop_back();
            }
            dfs(i+1, v);
        };
        for (int i=0; i<n-1; ++i){
            vector<int> v; v.push_back(nums[i]);
            dfs(i+1, v);  
        }
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};
