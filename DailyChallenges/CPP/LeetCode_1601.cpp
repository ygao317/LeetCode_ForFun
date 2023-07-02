class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int rn = requests.size(), ans = 0;
        for (int mask = (1 << rn)-1; mask>0; --mask){
            int c = __builtin_popcount(mask);
            if (c <= ans) continue;
            vector<int> cnt(n, 0);
            for (int i = 0; i<rn; ++i){
                if (mask & (1 << i)){ 
                    --cnt[requests[i][0]];
                    ++cnt[requests[i][1]];
                }
            }
            if (all_of(cnt.begin(), cnt.end(), [](auto& x){return x==0;}))
                ans = c;
        }
        return ans;
    }
};
