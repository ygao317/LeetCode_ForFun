class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        // BFS
        queue<TreeNode *> q; q.push(root);
        int ans = 0;
        while (!q.empty()){
            ++ans;
            int sz = q.size();
            for (int i=0; i<sz; ++i){
                auto node = q.front(); q.pop();
                if (!node->left && !node->right) return ans; 
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return ans;
    }
};
