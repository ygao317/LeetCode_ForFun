class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        long long ans = 0;
        vector<unordered_map<long long, int>> cnt(n);  // at each position, for each different, how many count
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                auto itr = cnt[j].find((long long)A[i]-A[j]);
                int sum = (itr != cnt[j].end()) ? (itr->second) : 0;
                ans += sum++;
                cnt[i][(long long)A[i]-A[j]] += sum;
            }
        }

        return ans;
    }
};
