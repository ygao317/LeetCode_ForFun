class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        long long sum = 0;
        int ans = 0;
        for (auto num: nums){
            sum += num;
            if (sum>0) ++ans; else return ans;
        }
        return ans;
    }
};
