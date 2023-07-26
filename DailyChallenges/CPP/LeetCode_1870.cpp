class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if (hour <= dist.size()-1) return -1;
        auto check = [&](int sp){
            double hr = 0;
            for (auto d: dist) hr = ceil(hr) + (double)d/sp;
            return hr>hour;
        };
        int l = 1, r = INT_MAX;
        while (l < r){
            int m = l + (r-l)/2;
            if (check(m)) l = m+1; else r = m;
        }
        return l;
    }
};
