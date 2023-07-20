class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        for (int i=0; i<nums.size(); ++i)
            nums[i] += (s[i] == 'L') ? -d : d;
        sort(nums.begin(), nums.end());
        int ans = 0; long long ls = 0;
        for (int i=1; i<nums.size(); ++i){
            ls = (ls + ((long long)nums[i]-nums[i-1]) * i) % (int)(1e9+7);
            ans = (ans + ls) % (int)(1e9+7);
        }
        return ans;
    }
};
