class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        map<int, int> cnt;
        for (int num: nums) ++cnt[num];

        int ans = 1;
        for (auto [n, c]: cnt){
            if (c == -1) continue;
            int dp0 = 1, dp1 = 0;
            int _n = n;
            while (cnt.count(_n)){
                int _dp0 = dp0 + dp1;
                dp1 = dp0 * ((1 << cnt[_n]) -1);
                dp0 = _dp0;
                cnt[_n] = -1;
                //cout << _n << " " << dp0 << " " << dp1 << endl;
                _n += k;
            }
            ans *= dp0 + dp1;
        }

        return ans - 1;
    }
};
