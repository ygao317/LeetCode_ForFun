class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        vector<int> ans(n, 0);
        for (int i=0; i<n; ++i){
            s.insert(nums[i]);
            ans[i] = s.size();
        }
        s.clear();
        for (int i=n-1; i>0; --i){
            s.insert(nums[i]);
            ans[i-1] -= s.size();
        }
        return ans;
    }
};
