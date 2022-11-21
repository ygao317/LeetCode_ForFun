// 2476. Closest Nodes Queries in a Binary Search Tree

class Solution {
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        function<vector<int>(TreeNode *, int)> bs = [](TreeNode *root , int q) -> vector<int> {
            TreeNode* p = root;
            int lb = INT_MIN, ub =  INT_MAX;
            while(p){
                if(p->val > q){
                    ub = min(ub , p->val); p =p->left;
                }else if(p->val < q){
                    lb = max(lb , p->val); p=p->right;   
                }else
                    return {p->val , p->val};
            }
            if(lb == INT_MIN) lb = -1;
            if(ub == INT_MAX) ub = -1;
            return {lb , ub};
        };
        
        vector<vector<int>> ans(queries.size());
        for (int i = 0; i<queries.size(); ++i)
            ans[i] = bs(root, queries[i]);
        
        return ans;
    }
};
