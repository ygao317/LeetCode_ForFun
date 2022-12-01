// 1704. Determine if String Halves Are Alike @ 2022/12/01

class Solution {
public:
    bool halvesAreAlike(string s) {
        auto isVol = [](char ch) {
            return set({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}).count(ch) > 0;};
        
        int h = s.size()/2;
        return count_if(s.begin(), s.begin()+h, isVol) == count_if(s.begin()+h, s.end(), isVol);
    }
};
