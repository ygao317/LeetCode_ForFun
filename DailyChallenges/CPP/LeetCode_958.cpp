class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q; q.push(root);
        bool end = false;
        while (!q.empty()){
            int sz = q.size();
            for (int i=0; i<sz; ++i){
                auto node = q.front(); q.pop();
                if (end && node->left) return false;
                if (!end && node->left) q.push(node->left);
                if (!end && !node->left) end = true;
                if (end && node->right) return false;
                if (!end && node->right) q.push(node->right);
                if (!end && !node->right) end = true;     
            }
        }
        return true;
    }
};
