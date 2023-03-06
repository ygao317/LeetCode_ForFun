class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        map<int,int> m;
        for (auto & r: ranges){
            m[r[0]]++; 
            m[r[1]]--;
        }
        int n = 0, sum = 0;
        for (auto [_, c]: m){
            sum += c;
            if (sum == 0) ++n;
        }
        long long ans = 1;
        while (n>0){
            if (n < 10) ans = (ans << n) % 1000000007;
            else ans = (ans << 10) % 1000000007;
            n -= 10;
        }
        
        return ans;
    }
};
