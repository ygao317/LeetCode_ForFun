class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ri(m*n+1,-1), ci(m*n+1, -1), rc(m, 0), cc(n, 0);
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j){
                ri[mat[i][j]] = i;
                ci[mat[i][j]] = j;
            }
        
        for (int i = 0; i < arr.size(); ++i){
            ++rc[ri[arr[i]]];
            ++cc[ci[arr[i]]];
            if (rc[ri[arr[i]]] == n || cc[ci[arr[i]]] == m) return i;
        }

        return -1;
    }
};
