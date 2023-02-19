class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode *> q; q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()){
            vector<int> v;
            int sz = q.size();
            for (int i = 0; i<sz; ++i){
                auto node = q.front(); q.pop();
                if (node){
                    v.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if (ans.size() % 2 == 1)
                reverse(v.begin(), v.end());
            if (!v.empty())
                ans.push_back(v);
        }
        return ans;
    }
};
