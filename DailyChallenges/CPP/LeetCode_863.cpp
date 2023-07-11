class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, vector<int>> m;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int v){
            if (node){
                m[node->val].push_back(v);
                m[v].push_back(node->val);
                dfs(node->left, node->val);
                dfs(node->right, node->val);
            }
        };
        if (root){ dfs(root->left, root->val); dfs(root->right, root->val); }
        vector<int> v(501, 0); v[target->val] = 1;
        queue<int> q; q.push(target->val);
        while (k-->0 && !q.empty()){
            int sz = q.size();
            for (int i=0; i<sz; ++i){
                int s = q.front(); q.pop();
                for (int d: m[s]){
                    if (v[d]) continue;
                    q.push(d); v[d] = 1;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()); q.pop(); 
        }
        return ans;
    }
};
