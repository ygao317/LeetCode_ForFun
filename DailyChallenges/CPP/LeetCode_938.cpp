// 938. Range Sum of BST @ 2022/12/07

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root){
            if (root->val < low)
                return rangeSumBST(root->right, low, high);
            else if (root->val > high)
                return rangeSumBST(root->left, low, high);
            else
                return root->val + rangeSumBST(root->right, low, high) + rangeSumBST(root->left, low, high);
        }else
            return 0;
    }
};
