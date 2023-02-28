class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> m;
        vector<TreeNode*> ans;
        function<string(TreeNode*)> dfs = [&](TreeNode* node){
            if (!node) return string("");
            string s = "(" + dfs(node->left) + "," + to_string(node->val) + "," + dfs(node->right)+ ")";
            if (m[s]++ == 1) ans.push_back(node);
            return s;
        };
        dfs(root);
        return ans;
    }
};
