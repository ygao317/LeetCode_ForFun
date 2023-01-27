class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        return (s.find('1') == string::npos) == (target.find('1') == string::npos);
    }
};
// 1 to 0 or 0 to 1 need one 1 to
// 0 0 => 0 0
// 0 1 => 1 1
// 1 0 => 1 1
// 1 1 => 1 0
