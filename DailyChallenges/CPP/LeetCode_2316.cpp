class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        
        function<int(int)> find = [&](int i) { return (p[i] == i)? p[i] : (p[i] = find(p[i])); };
    
        for (auto& e: edges){
            int i1 = find(e[0]);
            int i2 = find(e[1]);
            if (i1 != i2) p[i1] = i2;
        }

        unordered_map<int, int> m;
        for (int i=0; i<n; ++i)
            ++m[find(i)];
        
        long long ans = 0;
        for (auto [_, v]: m)
            ans += (n -= v) * (long long)v;

        return ans;
    }
};
