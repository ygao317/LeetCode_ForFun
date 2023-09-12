class Solution {
public:
    int minDeletions(string s) {
        vector<int> c(26, 0);
        for (auto ch: s) ++c[ch-'a'];
        sort(c.rbegin(), c.rend());
        int ans = 0, pre = c[0];
        for (int i = 1; i<26; ++i){
            if (c[i] == 0) break;
            if (pre == 0) ans += c[i];
            else if (c[i] >= pre) ans += c[i]-(--pre);
            else pre = c[i];
        }
        return ans;
    }
};
