class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> cnt(n, -1); cnt[n-1] = 0;
        for (int i=n-1; i>0; --i){
            if (cnt[i]==-1) continue;
            for (int j = i-1; j>=0; --j)
                if (abs(nums[i] - nums[j])<= target)
                    cnt[j] = max(cnt[j], cnt[i]+1);
        }
        return cnt[0];
    }
};
