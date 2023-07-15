class Solution {
public:
    long long minimumCost(string s) {
        int n = s.size();
        auto cnt = [&](int m){
            long long r = 0;
            for (int i = 0; i< n/2+1; ++i)
                if (s[i]-'0' == m)
                    r += i,  m = 1-m;
            
            for (int i = n/2; i<n; ++i)
                if (s[i]-'0' == m)
                    r += n-i, m = 1-m;
            return r;
        };
        return min(cnt(0), cnt(1));
    }
};
