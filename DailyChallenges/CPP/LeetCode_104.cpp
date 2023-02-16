class Solution {
public:
    int maxDepth(TreeNode* root) {
        int ans = 0;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* t, int n){
            if (!t) 
                ans = max(ans, n);
            else{
                dfs(t->left, n+1);
                dfs(t->right, n+1);
            }
        };
        dfs(root, 0);
        return ans;
    }
};
