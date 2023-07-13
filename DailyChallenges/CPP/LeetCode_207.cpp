class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> es(n);
        vector<int> d(n, 0);
        for (auto& e : prerequisites)
            es[e[1]].push_back(e[0]), d[e[0]]++;
        
        vector<int> ts;
        for (int i = 0; i < n; ++i) if (!d[i]) ts.push_back(i);
        
        for (int i = 0; i < ts.size(); ++i)
            for (int j: es[ts[i]])
                if (--d[j] == 0) ts.push_back(j);
        
        return ts.size() == n;
    }
};
