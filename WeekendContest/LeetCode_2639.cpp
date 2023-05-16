class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size(), 0);
        for (auto & row: grid)
            for (int i = 0; i<row.size(); ++i)
                ans[i] = max(ans[i], (int)to_string(row[i]).size());
        return ans;
    }
};
