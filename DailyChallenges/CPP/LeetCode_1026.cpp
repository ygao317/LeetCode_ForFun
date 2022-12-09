// 1026. Maximum Difference Between Node and Ancestor @ 2022/12/09
 
class Solution {
public:

    int maxAncestorDiff(TreeNode* root) {
        int ans = -1;

        function<void(TreeNode*, int, int)> dfs = [&](TreeNode* node, int lmax, int lmin){
            lmax = max(lmax, node->val);
            lmin = min(lmin, node->val);
            if (node->left) dfs(node->left, lmax, lmin);
            if (node->right) dfs(node->right, lmax, lmin);
            if (!node->left & !node->right) ans = max(ans, lmax-lmin);
        };

        dfs(root,root->val, root->val);
        return ans;
    }
};
