// 2477. Minimum Fuel Cost to Report to the Capital

class Solution {
public:    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<vector<int>> e(roads.size() + 1); // prepare the edges 
        for (auto &r : roads) 
            e[r[0]].push_back(r[1]),e[r[1]].push_back(r[0]);
        
        long long ans = 0;
        function<int(int,int,int)> dfs = [&](int i, int pre, int depth){
            int riders = 1; // current node
            for (int j : e[i])
                if (j != pre)
                    riders += dfs(j, i, depth + 1);
            if (depth == 0) return 0;
            ans += (riders / seats) * depth + (riders % seats ? 1 : 0); // Nice here
            return riders % seats;
        };
        
        dfs(0, -1, 0);
        return ans;
    }
};
