class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> cnt(k); cnt[0] = 1;
        int prefix = 0, ans = 0;
        for (int n: nums){
            prefix = (prefix + n%k +k) % k;
            ans += cnt[prefix]++;
        }
        return ans;
    }
};
