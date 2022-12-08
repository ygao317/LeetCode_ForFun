class Solution {
public:
    void dfs(TreeNode* root,vector<int>& v){
        if(!root) return;
        if(!root->left && !root->right) v.push_back(root->val);
        dfs(root->left,v);
        dfs(root->right,v);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v,m;
        dfs(root1,v);
        dfs(root2,m);
        return v == m;
    }
};
