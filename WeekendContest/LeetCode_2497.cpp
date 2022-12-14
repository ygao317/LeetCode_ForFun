class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int ans = *max_element(vals.begin(), vals.end());
            
        // build up the map
        unordered_map<int, vector<int>> m;
        for (auto& e: edges){
            m[e[0]].push_back(e[1]);
            m[e[1]].push_back(e[0]);
        }
        
        for (auto [c, v]: m){
            sort(v.begin(), v.end(), [&vals](int n1, int n2){return vals[n1]>vals[n2]; });
            int s = vals[c];
            for (int i=0; i<k && i<v.size(); ++i){
                s += vals[v[i]];
                ans = max(ans, s);
            }
        }
        
        return ans ;
    }
};
