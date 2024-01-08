class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        function<void(TreeNode*, int, int)> sum = [&](TreeNode* node, int l, int r) {
            if (!node) return;
            if (node->val > high) // only go to low side
                sum(node->left, l, r);
            else if (node->val < low)
                sum(node->right, l, r);
            else{
                ans += node->val;
                sum(node->left, l, node->val);
                sum(node->right, node->val, r);
            }
        };
        sum(root, low, high);
        return ans;
    }
};
