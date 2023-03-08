/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> v;
        queue<TreeNode *> q; q.push(root);
        while (!q.empty()){
            long long _sum = 0LL;
            int sz = q.size();
            for (int i=0; i<sz; ++i){
                auto node = q.front(); q.pop();
                _sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            v.push_back(_sum);
        }
        if (k> v.size()) return -1;
        return nth_elements(v.rbegin(), v.rend(), k);
    }
};
