class Solution {
public:
    int minimizedStringLength(string s) {
        vector<int> cnt(26);
        for (auto ch: s) ++cnt[ch-'a'];
        return count_if(cnt.begin(), cnt.end(), [](auto x) { return x!= 0;});
    }
};
