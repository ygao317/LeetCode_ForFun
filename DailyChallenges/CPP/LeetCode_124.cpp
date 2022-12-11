// 124. Binary Tree Maximum Path Sum @ 2022/12/11
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        function<int(TreeNode*)> dfs = [&](TreeNode * node){
            if (!node) return 0;
            int l = dfs(node->left);
            int r = dfs(node->right);
            ans = max(ans, ((l>0)?l:0) + node->val + ((r>0)?r:0));
            return max(((l>0)?l:0), ((r>0)?r:0)) + node->val;
        };
        dfs(root);
        return ans;
    }
};
