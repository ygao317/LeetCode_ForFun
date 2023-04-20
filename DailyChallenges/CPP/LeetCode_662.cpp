class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        long long max_width = 1;
        queue<pair<TreeNode*, long long>> q; q.push({root, 0});
        while (!q.empty()) {
            max_width = max(max_width, q.back().second - q.front().second + 1);
            int n = q.size();
            long long st = q.front().second;
            for (int i = 0; i < n; ++i) {
                auto [node, idx] = q.front(); q.pop();
                if (node->left) q.push({node->left, 2 * (idx-st)});
                if (node->right) q.push({node->right, 2 * (idx-st) + 1});
            }
        }
        return max_width;
    }
};
