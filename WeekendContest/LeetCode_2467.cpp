// 2467. Most Profitable Path in a Tree 

class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        unordered_map<int, vector<int>> m;
        for (auto & a: edges){
            m[a[0]].push_back(a[1]);
            m[a[1]].push_back(a[0]);
        }
        
        // find the path from bob to 0
        vector<int> path; path.push_back(bob);
        function<bool(void)> dfs1 = [&] () {
            if (path.back() == 0) { // find the bob to zero path and update it.
                int sz = path.size(), i = 0;
                for ( ; i<sz/2; ++i) amount[path[i]] = 0;
                if (sz%2 == 1) amount[path[i]] = amount[path[i]] / 2;
                return true;
            }

            if (path.size()>1 && m[path.back()].size() == 1) { // reach leaf
                return false;
            }

            bool stop;
            for (auto node: m[path.back()]){
                if (path.size()>1 && path[path.size()-2] == node) continue;
                path.push_back(node); stop = dfs1(); path.pop_back();
                if (stop) break;
            }
            return stop;
        }; dfs1();
    
        // dfs to find the maximum amount
        int ans = INT_MIN;
        path.clear(); path.push_back(0);
        function<void(int)> dfs2 = [&](int profit) {
            if (path.size() > 1 && m[path.back()].size() == 1) { // reach leaf
                ans = max(ans, profit);
                return;
            }

            for (auto node: m[path.back()]){
                if (path.size()>1 && path[path.size()-2] == node) continue;
                path.push_back(node); dfs2(profit + amount[node]); path.pop_back();
            }
        }; dfs2(amount[0]);

        return ans;
    }
};
