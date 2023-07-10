class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        vector<int> d = {0, 0, -1, -1, 0};
        map<pair<int, int>, int> mp;
        for (auto &a: coordinates){
            for (int i=0; i<4; ++i){
                int _x = a[0] + d[i];
                int _y = a[1] + d[i+1];
                if (_x < 0 || _y < 0 || _x == m-1 || _y == n-1) continue;
                ++mp[{_x, _y}];
            }
        }

        vector<long long> ans = {(long long)(m-1) * (n-1) - (long long)mp.size(), 0, 0, 0, 0};
        for (auto &[_, c]: mp) ++ans[c];

        return ans;
    }
};
