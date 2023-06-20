class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if (k==0) return nums;
        
        int n = nums.size(), w = 2*k+1;
        vector<int> ans(n, -1);
        if (w > n) return ans;

        long long ls = 0;
        for (int i=0; i<n; ++i){
            ls += nums[i];
            if (i>=w) ls -= nums[i-w];
            if (i>=w-1) ans[i-k] = ls / w;
        }
        
        return ans; 
    }
};
