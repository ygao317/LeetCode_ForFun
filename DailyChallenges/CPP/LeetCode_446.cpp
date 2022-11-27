// 446. Arithmetic Slices II - Subsequence @ 2022/11/27

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        long long ans = 0;
        vector<unordered_map<long long, int>> cnt(n);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long delta = (long long)A[i] - A[j];
                int sum = (cnt[j].find(delta) != cnt[j].end()) ? cnt[j][delta] : 0;
                ans += sum++;
                cnt[i][delta] += sum;
            }
        }

        return ans;
    }
};
