class Graph {
public:
    vector<vector<int>> am;
    Graph(int n, vector<vector<int>>& edges) {
        am = vector<vector<int>>(n, vector<int>(n, 1e9));
        for (auto &e : edges)
            am[e[0]][e[1]] = e[2];
        for (int i = 0; i < n; ++i)
            am[i][i] = 0;
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    am[i][j] = min(am[i][j], am[i][k] + am[k][j]);
    }
    void addEdge(const vector<int> &e) {
        if (am[e[0]][e[1]] <= e[2]) return;
        for (int i = 0; i < am.size(); ++i)
            for (int j = 0; j < am.size(); ++j)
                am[i][j] = min(am[i][j], am[i][e[0]] + am[e[1]][j] + e[2]);
    }
    int shortestPath(int n1, int n2) {
        return am[n1][n2] == 1e9 ? -1 : am[n1][n2];
    }
};
