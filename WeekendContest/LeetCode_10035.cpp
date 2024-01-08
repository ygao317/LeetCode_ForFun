class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int d = 0, a = 0;
        for (auto & r:dimensions){
            int ld = r[0]*r[0] + r[1]*r[1];
            if (ld >= d){
                a= (ld == d)? max(a, r[0]*r[1]) : r[0]*r[1];
                d = ld;
            }
        }
        return a;
    }
};
