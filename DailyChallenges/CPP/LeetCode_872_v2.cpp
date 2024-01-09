class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves;
        function<void(TreeNode*)> pop = [&](TreeNode* node){
            if (!node->left && !node->right) leaves.push_back(node->val);
            if (node->left) pop(node->left);
            if (node->right) pop(node->right);
        };
        pop(root1);
        function<bool(TreeNode*)> check = [&](TreeNode* node){
            bool ck = true;
            if (!node->left && !node->right){
                if (leaves.empty() || leaves.back() != node->val)
                    ck = false;
                else
                    leaves.pop_back();
            }else{
                if (ck && node->right) ck = check(node->right);
                if (ck && node->left) ck = check(node->left);
            }
            return ck;
        };

        return check(root2) && leaves.empty();
    }
};
