class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int num: nums) ++cnt[num];
        
        int ans = 0, n = nums.size();
        for (int l = 0; l < n; ++l){
            unordered_map<int, int> tmp(cnt.begin(), cnt.end());
            int r = n-1;
            while (tmp[nums[r]] > 1) --tmp[nums[r--]];
            ans += n-r;
            if (cnt[nums[l]] == 1) break; else --cnt[nums[l]];
        }
        return ans; 
    }
};
