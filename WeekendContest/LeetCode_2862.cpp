class Solution {
public:
    long long maximumSum(vector<int>& A) {
        long long res = 0;
        for (int k = 1; k <= A.size(); k++)
            for (long long cur = 0, v = 1; v * v * k <= A.size(); v++)
                res = max(res, cur += A[k * v * v - 1]);
        return res;
    }
};
