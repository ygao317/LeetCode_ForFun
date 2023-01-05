class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans = 0, end = points[0][1];
        for (auto& a: points){
            if (a[0] > end){
                end = a[1];
                ++ans;
            } else
                end = min(end, a[1]);
        }
        return ans+1;
    }
};
