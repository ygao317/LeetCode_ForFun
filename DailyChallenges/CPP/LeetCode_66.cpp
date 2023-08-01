class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        int m = (2*k <= n) ? k : n-k;

        vector<vector<int>> res; res.push_back({});
        for (int t=1; t <= m; ++t){
            vector<vector<int>> tmp;
            for (auto& v: res){
                for (int num = (v.empty()?1:(v.back()+1)); num <= n; ++num){
                    tmp.push_back(v);
                    tmp.back().push_back(num);
                }
            }
            tmp.swap(res);
        }

        if (m != k)
            for (auto& v: res){
                int i = 0;
                for (int num=1; num<=n; ++num)
                    if (i<m && num == v[i]) ++i; else v.push_back(num); 
                v.erase(v.begin(), v.begin()+m);
            }
        
        return res;
    }
};
