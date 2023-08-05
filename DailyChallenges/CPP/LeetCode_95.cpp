class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<vector<TreeNode* > > > dp(n+1, vector<vector<TreeNode*> > (n+2, vector<TreeNode*>())); 
        for (int i=0; i<=n; ++i) {
            dp[i][i] = {nullptr};
            dp[i][i+1] = {new TreeNode(i+1)};
        }
        function<vector<TreeNode*>(int, int)> dfs = [&](int l, int r){
            if (!dp[l][r].empty()) return dp[l][r];
            vector<TreeNode*> res;
            for (int i = l; i<r; ++i)
                for (auto ln: dfs(l, i))
                    for (auto rn: dfs(i+1,r))
                        res.push_back(new TreeNode(i+1, ln, rn));
            return dp[l][r] = res;
        };

        return dfs(0, n);
    }
};
