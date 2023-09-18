class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size(), lm = 0;
        unordered_map<int, int> m;
        for (auto num: nums) 
            lm = max(lm, ++m[num]);

        return (lm <= n/2)? (n%2==0?0:1) : (lm*2 - n);
    }
};
