class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> ps(n+1, 0); 
        for (int i=1; i<=n; ++i) ps[i] = ps[i-1] + nums[i-1];

        int qn = queries.size();
        vector<long long> ans(qn, 0);
        for (int i=0; i<qn; ++i){
            long long q = queries[i];
            int l = lower_bound(nums.begin(), nums.end(), q) - nums.begin();
            ans[i] = q * (2 * l - n) + ps[n] - 2 * ps[l];
        }

        return ans;
    }
};
