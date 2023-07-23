class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n%2 == 0) return {};
        if (n == 1) return { new TreeNode(0) };
        vector<TreeNode*> res;
        for (int i = 1; i<n-1; i+=2)
            for (auto l: allPossibleFBT(i))
                for (auto r: allPossibleFBT(n-1-i))
                    res.push_back( new TreeNode(0, l, r) );
        return res;
    }
};
