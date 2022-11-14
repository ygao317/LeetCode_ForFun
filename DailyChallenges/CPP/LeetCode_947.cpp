// 947. Most Stones Removed with Same Row or Column @ 2022/11/14

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        
        function<int(int)> findIt = [&p, &findIt](int i) {
            return (p[i] == i) ? i : (p[i] = findIt(p[i]));
        };
        
        function<void(int,int)> unionIt = [&p, &findIt](int i, int j){ 
            p[findIt(i)]=findIt(j); 
        };
        
        unordered_map<int, vector<int>> xs, ys; 
        for (int i=0; i< n; ++i){
            int x = stones[i][0], y = stones[i][1];
            xs[x].push_back(i);
            ys[y].push_back(i);
            if (xs[x].size()>1) unionIt(i, xs[x][0]);
            if (ys[y].size()>1) unionIt(i, ys[y][0]);
        }
        
        unordered_set<int> s;
        for (int i=0; i<n; ++i){
            s.insert(findIt(i));
        }
        
        return n - s.size();
    }
};
