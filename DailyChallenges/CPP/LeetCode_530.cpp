class Solution { // Binary Search Tree => sorted and without duplication => overthink
public:
    int getMinimumDifference(TreeNode* root) {
        set<int> s;
        int ans = INT_MAX;
        function<void(TreeNode*)> check = [&](TreeNode * node){
            if (!node) return;
            auto itr = s.lower_bound(node->val);
            if (itr != s.end()) ans = min(ans, *itr - node->val );
            if (itr != s.begin()) ans = min(ans, node->val - *prev(itr));
            if (ans == 0) return;
            s.insert(node->val);
            check(node->left);
            check(node->right);
        };
        check(root);
        return ans;
    }
};
