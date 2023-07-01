class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        sort(cookies.rbegin(),cookies.rend());
        int fair = accumulate(cookies.begin(), cookies.end(), 0) / k;
        vector<int> v(k);
        int ans = INT_MAX, n = cookies.size();
        function<void(int)> dfs = [&](int c){
            for(int i=0; i<k; ++i){
                if (i>0 && v[i] == v[i-1]) continue;
                if (v[i] >= fair) continue;
                v[i] += cookies[c];
                if (c == n-1) ans = min(ans, *max_element(v.begin(), v.end()));
                else dfs(c+1);
                v[i] -= cookies[c];
            }
        };
        dfs(0);
        return ans;
    }
};
