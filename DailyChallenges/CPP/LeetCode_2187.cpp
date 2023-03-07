class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        function<bool(long long)> count = [&](long long t) {
            long long ans = 0;
            for (int pt: time){
                ans += t/pt;
                if (ans >= totalTrips) return false;
            }
            return true;
        };

        long long l = 1LL, r = 1e14;
        while (l < r){
            long long m = l+(r-l)/2;
            if (count(m)) l = m+1; else r = m; 
        }

        return l;
    }
};
