class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        function<void (TreeNode*, int)> dfs = [&](TreeNode* node, int sum){
            int _sum = sum * 10 + node->val;
            if (!node->left && !node->right) { ans += _sum; }
            if (node->left) dfs(node->left, _sum);
            if (node->right) dfs(node->right, _sum);
        };
        dfs(root, 0);
        return ans;
    }
};
