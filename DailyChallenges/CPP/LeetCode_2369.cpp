class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> df(n+1, false); df[0] = true;
        for (int i = 1; i<n; ++i){
            df[i+1] = df[i-1] && nums[i] == nums[i-1];
            if (df[i+1] || i<2) continue;
            df[i+1] = df[i-2] && ((nums[i] == nums[i-1] && nums[i-1] == nums[i-2]) || (nums[i] == nums[i-1]+1 && nums[i-1] == nums[i-2]+1));
        }
        return df[n];
    }
};
