class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> ps = {0}; 
        vector<pair<int, TreeNode*>> chs = {{0, root}};
        while (!chs.empty()){
            int sm = 0;
            for (int num: ps) sm += num;
            vector<int> ps_t(chs.size()); 
            vector<pair<int, TreeNode*>> chs_t;
            for (int i = 0; i<chs.size(); ++i){
                auto [pi, node] = chs[i];
                node->val = sm - ps[pi]; // update
                if (node->left){
                    ps_t[i] += node->left->val;
                    chs_t.push_back({i, node->left});
                }
                if (node->right){
                    ps_t[i] += node->right->val;
                    chs_t.push_back({i, node->right});
                }
            }
            chs.swap(chs_t);
            ps.swap(ps_t);
        }
        return root;
    }
};
