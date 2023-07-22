class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<int> d = {1,2,1,-2,-1,2,-1,-2, 1};
        map<vector<int>, double> m;
        function<double(int,int,int)> dfs = [&](int r, int c, int t){
            if (r < 0 || r >=n || c < 0 || c >= n) return 0.;
            if (t == k) return 1.;
            if (m[{r, c, t}] > 0) return m[{r, c, t}];
            double p = 0;
            for (int i = 0; i < 8; ++i)
                p += 1 / 8. * dfs(r + d[i], c + d[i+1], t+1);
            return m[{r, c, t}] = p;
        };
        return dfs(row, column, 0);
    }
};
