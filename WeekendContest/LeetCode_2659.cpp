class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        long long n = nums.size(), res = n;
        vector<int> pos(n);
        iota(begin(pos), end(pos), 0);
        sort(begin(pos), end(pos), [&](int a, int b) {return nums[a] < nums[b];});
        for (int i = 1; i < n; ++i)
            if (pos[i] < pos[i - 1])
                res += n - i;
        return res;
    }
};
