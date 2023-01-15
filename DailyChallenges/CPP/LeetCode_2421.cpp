class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();

        // union find
        vector<int> parent(n); iota(parent.begin(), parent.end(), 0); 
        function<int(int)> find = [&](int x){
            return (x == parent[x]) ? x : (parent[x] = find(parent[x])); 
        };

        // replace traditional edges
        vector<vector<int>> sortValEdges; // max, node0, node1
        for(auto edge : edges)
            sortValEdges.push_back({max(vals[edge[0]], vals[edge[1]]), edge[0], edge[1]});
        sort(sortValEdges.begin(), sortValEdges.end());

        unordered_map<int, unordered_map<int,int>> valueFreqMap; // node -> value -> cnt
        for(int i = 0; i < n; i++)
            valueFreqMap[i][vals[i]] = 1;

        int res = n;
        for(auto &x : sortValEdges) {
            int currVal = x[0];
            int iFather = find(x[1]);
            int jFather = find(x[2]);
            int iCount = valueFreqMap[iFather][currVal];
            int jCount = valueFreqMap[jFather][currVal];
            res += iCount*jCount;
            parent[jFather] = iFather;
            valueFreqMap[iFather][currVal] = iCount + jCount;
        }
        return res;
    }
    
};
