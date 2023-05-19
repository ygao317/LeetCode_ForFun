class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> ans(graph.size(), 0); // bw => 1 or -1 
        function<bool(int, int)> mark = [&](int i, int bw){
            if (ans[i] == bw) return true;
            else if (ans[i] == -bw) return false;
            else {
                ans[i] = bw;
                for(int j: graph[i])
                    if (!mark(j, -bw))
                        return false;
                return true;
            }
        };
        for(int i=0; i<graph.size(); ++i){
            if (ans[i]) continue;
            if (!mark(i, 1)) return false;
        }
        return true;
    }
};
