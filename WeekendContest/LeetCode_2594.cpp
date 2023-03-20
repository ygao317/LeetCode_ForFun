class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        map<int, int> cnt;
        for (int r: ranks) ++cnt[r];
        
        function<bool(long long)> canFinish = [&](double time){
            long long _cars = 0;
            for (auto& [r, c]: cnt){
                _cars += (long long)(sqrt(time/r)) * c;
                if (_cars >= cars) return true;
            }
            return false;
        };
        
        long long l = 0, r = LLONG_MAX;
        while (l<r){
            long long m = l + (r-l)/2;
            if (canFinish(double(m))) r = m; else l = m+1;
        }
        return l;
    }
};
