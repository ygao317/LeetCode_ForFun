class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& M) {
        int m = M.size(), n = M[0].size();
        map<int, vector<int>> A; // group the value first, map is ordered by default
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                A[M[i][j]].push_back(i * n + j);
        vector<vector<int>> dp(m, vector<int>(n, 0)); // m * n
        vector<int> res(n + m, 0); // track the max value in each r and each c
        for (auto& [a, pos] : A) {
            for (int p : pos) {
                int i = p / n, j = p % n;
                dp[i][j] = max(res[i], res[m + j]) + 1;
            }
            for (int p : pos) { // refresh
                int i = p / n, j = p % n;
                res[m + j] = max(res[m + j], dp[i][j]);
                res[i] = max(res[i], dp[i][j]);
            }
        }
        return *max_element(res.begin(), res.end());
    }
};
