class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        vector<int> pos(m, 0), ans(m, 0);
        for (int i = 0; i<m; ++i){
            pos[i] = distance(mat[i].rbegin(), upper_bound(mat[i].rbegin(), mat[i].rend(), 0));
            ans[i] = i;
        }
        
        sort(ans.begin(), ans.end(), [&](int i, int j){
            return pos[i]>pos[j] || (pos[i] == pos[j] && i < j);
        });

        ans.resize(k);
        return ans;
    }
};
