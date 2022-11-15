// 222. Count Complete Tree Nodes @ 2022/11/15

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        int l = 1, r = 1;
        TreeNode *ptr_r = root, *ptr_l = root;
        while (ptr_l = ptr_l->left) l++; // got the height from left
        while (ptr_r = ptr_r->right) r++; /// got the height from right
        
        if (l == r) 
            return pow(2, l) - 1;
        else
            return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
