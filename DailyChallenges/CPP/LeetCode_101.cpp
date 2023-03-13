class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        function<bool(TreeNode*, TreeNode*)> isSym = [&](TreeNode* a, TreeNode* b){
            return (!a && !b) || (a && b && a->val == b->val && isSym(a->left, b->right) && isSym(a->right, b->left));
        };

        return isSym(root, root);
    }
};
