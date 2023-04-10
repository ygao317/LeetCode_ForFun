class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size(), steps = 0;
        vector<int> max_i(n), max_j(m); // max i reached for each column or max j reached for each row
        vector<pair<int, int>> q{{0, 0}}, q1;
        while (!q.empty()) {
            ++steps;
            for (auto [i, j] : q) {
                if (i == m - 1 && j == n - 1)
                    return steps;
                for (int k = max(max_i[j], i) + 1; k < m && k - i <= g[i][j]; ++k)
                    q1.push_back({k, j});
                for (int k = max(max_j[i], j) + 1; k < n && k - j <= g[i][j]; ++k)
                    q1.push_back({i, k});
                max_i[j] = max(max_i[j], i + g[i][j]);
                max_j[i] = max(max_j[i], j + g[i][j]);
            }
            swap(q, q1);
            q1.clear();
        }
        return -1;
    }
};
