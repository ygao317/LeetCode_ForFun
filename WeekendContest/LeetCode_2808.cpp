class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n = nums.size(), res = INT_MAX;
        unordered_map<int, vector<int>> m;
        for (int i=0; i<n; ++i) m[nums[i]].push_back(i);
        for (auto [_, v]: m){
            int lmax = (v[0] + n - v.back())/2;
            for (int i=1; i<v.size(); ++i)
                lmax = max(lmax, (v[i] - v[i-1])/2);
            res = min(res, lmax);
        }
        return res;
    }
};
