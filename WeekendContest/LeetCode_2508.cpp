class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> al(n + 1);
        vector<int> odd;    
        for (auto &e : edges) {
            al[e[0]].insert(e[1]);
            al[e[1]].insert(e[0]);
        }
        for (int i = 1; i <= n; ++i)
            if (al[i].size() % 2 == 1)
                odd.push_back(i);
        if (odd.size() == 2)
            for (int i = 1; i <= n; ++i)
                if (al[odd[0]].count(i) == 0 && al[odd[1]].count(i) == 0) // find a node not connected to both
                    return true;
        if (odd.size() == 4) // Choose 2 from 4 / 2 = 4 * 3 / 2 / 2 = 3 scenario
            return (al[odd[0]].count(odd[1]) == 0 && al[odd[2]].count(odd[3]) == 0)
                || (al[odd[0]].count(odd[2]) == 0 && al[odd[1]].count(odd[3]) == 0)
                || (al[odd[0]].count(odd[3]) == 0 && al[odd[1]].count(odd[2]) == 0);
        
        return odd.size() == 0;
    }
};
