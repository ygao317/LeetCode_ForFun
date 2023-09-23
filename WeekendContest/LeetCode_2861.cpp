class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        auto possible = [&](long long m){
            for (int i = 0; i<k; ++i){
                long long c = 0;
                for (int j = 0; j<n; ++j){
                    c += max(composition[i][j] * m - stock[j], 0LL) * cost[j];
                    if (c>budget) break;
                }
                if (c <= budget) return true;
            }
            return false;
        };
        
        int l = 0, r = INT_MAX;
        while (l<r){
            int m = l + (r-l)/2;
            if (possible(m)) l = m+1; else r=m;
        }
        return l-1;
    }
};
