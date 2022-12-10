// 1339. Maximum Product of Splitted Binary Tree @ 2022/12/10
class Solution {
public:
    int maxProduct(TreeNode* root) {
        vector<long long> sums;
        function<long long(TreeNode*)> dfs = [&](TreeNode* node){
            long long sum = node->val;
            if (node->left) sum += dfs(node->left);
            if (node->right) sum += dfs(node->right);
            sums.push_back(sum);
            return sum;
        };
        long long total = dfs(root);
        sort(sums.begin(), sums.end());
        auto itr = lower_bound(sums.begin(), sums.end(), total/2);
        long long ans = *itr * (total - *itr);
        if (itr-- != sums.begin())
            ans = max(ans, *itr * (total - *itr));
        return ans % 1000000007;
    }
};
