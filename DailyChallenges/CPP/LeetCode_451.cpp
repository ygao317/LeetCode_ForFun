// 451. Sort Characters By Frequency @ 2022/12/03

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for (auto ch:s)
            ++m[ch];
        sort(s.begin(), s.end(), [&m](const char& c1, const char& c2){ return m[c1]==m[c2] ? c1 >c2 : m[c1]>m[c2]; });
        return s;
    }
};
