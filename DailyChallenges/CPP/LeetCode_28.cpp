class Solution {
public:
    int strStr(string haystack, string needle) {
        auto r = haystack.find(needle);
        return (r == string::npos) ? -1 : r;
    }
};
