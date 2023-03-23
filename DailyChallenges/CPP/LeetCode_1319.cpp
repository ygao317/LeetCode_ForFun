class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) return -1;
    
        vector<int> p(n, -1);
        iota(p.begin(), p.end(), 0);

        function<int(int)> find = [&](int i) {
            if (p[i] == i) return i; else return p[i] = find(p[i]);
        };

        for (auto &c: connections){
            int i1 = find(c[0]);
            int i2 = find(c[1]);
            if (i1 != i2) p[i1] = i2;
        }

        int ans = 0;
        for (int i = 0; i<n; ++i)
            if (find(i) == i) ++ans;

        return ans-1;
    }
};
