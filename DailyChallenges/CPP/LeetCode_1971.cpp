class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;
        unordered_map<int, vector<int>> m;
        for (auto e: edges)
            m[e[0]].push_back(e[1]), m[e[1]].push_back(e[0]);

        vector<bool> visited(n, false); visited[source] = true;
        queue<int> q; q.push(source);
        while (!q.empty()){
            int sz = q.size();
            for (int i=0; i<sz; ++i){
                int src = q.front(); q.pop();
                for (auto des: m[src]){
                    if (des == destination) return true;
                    if (!visited[des]){
                        q.push(des);
                        visited[des] = true;
                    }
                }
            }
        }
        return false;
        // function<bool(int)> dfs = [&](int src){
        //     visited[src] = true;
        //     if (src == destination) return true;
        //     for (auto& des: m[src])
        //         if (!visited[des] && dfs(des)) return true;
        //     return false;
        // };
        // return dfs(source);
    }
};
