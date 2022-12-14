// 198. House Robber @ 2022/12/14

class Solution {
public:
    int rob(vector<int>& nums) {
        int t[2] = {0};
        for (int n: nums){
            int tmp = max(t[0] + n, t[1]);
            t[0] = t[1];
            t[1] = tmp;
        }
        return max(t[0], t[1]);
    }
};
