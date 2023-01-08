class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;
        for (int i = 0; i < points.size(); ++i){
            unordered_map<double, int> cnt;
            for (int j=0; j < points.size(); ++j){
                if (j == i) continue;
                if (points[i][0] == points[j][0]) ++cnt[INT_MAX];
                ++cnt[double(points[i][1] - points[j][1])/(points[i][0] - points[j][0])];
            }

            for (auto [_, c]: cnt)
                ans = max(ans, c+1);
        }
        return ans;
    }
};
