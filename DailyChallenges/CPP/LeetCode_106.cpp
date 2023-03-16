class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        function<TreeNode*(int, int, int, int)> build = [&](int ist, int ied, int pst, int ped) -> TreeNode * {
            if (ist > ied || pst > ped) return nullptr;
            int t = ist;
            while(inorder[t] != postorder[ped]) ++t;

            TreeNode* node = new TreeNode(postorder[ped]);
            node->left = build(ist, t-1, pst, pst+t-ist-1);
            node->right = build(t+1, ied, ped-(ied-t), ped-1);
            return node;
        };
        return build(0,inorder.size()-1,0,postorder.size()-1);
    }
};
