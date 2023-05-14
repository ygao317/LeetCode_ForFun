class Solution {
public:
    const int kMod = 1e9+7;
    long long pw(long long a, long p) {
        long long r = 1;
        while (p--)
            r = (r * a)%kMod;
        return r;
    }
    
    int sumOfPower(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long prev = 0;
        long long ans = 0;
        for (int num : nums) {
            ans = (ans + (long long)pw(num, 3))%kMod;
            ans = (ans + ((long long)pw(num, 2)* prev)%kMod)%kMod;
            prev = (prev*2 + num)%kMod;
        }
        return ans;
    }
};
