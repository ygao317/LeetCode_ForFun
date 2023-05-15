class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int c = count(nums.begin(), nums.end(), 1);
        if (c > 0) return n-c;
        int ans = INT_MAX;
        for (int i=0; i<n; ++i)
            for (int j=i+1; j<n; ++j)
                if ((nums[i] = gcd(nums[i], nums[j])) == 1){
                    ans = min(ans, j-i+(n-1));
                    break;
                }
        return (ans == INT_MAX) ? -1 : ans;
    }
};
