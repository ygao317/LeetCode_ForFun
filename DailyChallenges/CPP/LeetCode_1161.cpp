class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        // BFS
        queue<TreeNode *> q; q.push(root);
        int lv = 0, mx = INT_MIN, _lv = 1;
        while (!q.empty()){
            int _mx = 0;
            int _sz = q.size();
            for (int i=0; i<_sz; ++i){
                auto node = q.front(); q.pop();
                _mx += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (_mx > mx){ mx = _mx; lv = _lv; }
            _lv++;
        }
        return lv;
    }
};
