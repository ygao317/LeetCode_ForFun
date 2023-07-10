class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int ans = -1, l = -1, n = nums.size();
        for (int i = 1; i < n; ++i){
            if (l != -1 && nums[i] - nums[i-1] != ((i-l)%2 == 0?-1:1)) {
                ans = max(ans, i-l);
                //cout << i << " " <<l << endl;
                l = -1;
            } 
            if (nums[i] == nums[i-1] + 1 && l == -1) l = i-1;
        }
        if (l != -1) ans = max(ans, n-l);
        return ans;
    }
};
