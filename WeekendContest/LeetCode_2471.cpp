// 2471. Minimum Number of Operations to Sort a Binary Tree by Level

class Solution {
public:
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode *> q; q.push(root);

        while (!q.empty()){
            int sz = q.size();
            vector<int> vals, ords(sz);

            for (int i=0; i<sz; ++i){
                TreeNode* node = q.front(); q.pop();
                vals.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            iota(ords.begin(), ords.end(), 0);
            sort(ords.begin(), ords.end(), [&vals](int i, int j) { return vals[i] < vals[j]; });

            int i = 0;
            while (i<sz){
                if (i != ords[i])
                    swap(ords[i], ords[ords[i]]), ++ans;
                else
                    ++i;
            }
        }
        return ans;
    } 
};
