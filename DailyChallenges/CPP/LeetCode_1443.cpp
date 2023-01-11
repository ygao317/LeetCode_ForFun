class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> m;
        for (auto& e: edges)
            m[e[0]].push_back(e[1]), m[e[1]].push_back(e[0]);

        int ans = 0;
        function<bool(int, int)> cntTime = [&](int node, int parent) {
            bool ha = hasApple[node];
            for (int ch: m[node]){
                if (ch != parent){
                    bool cha = cntTime(ch, node);
                    if (cha) ++ans;
                    ha = ha | cha;
                }
            }
            return ha;
        };
        cntTime(0,-1);
        return ans*2;
    }
};
