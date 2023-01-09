class Solution {
public:
    bool isItPossible(string word1, string word2) {
        unordered_map<char, int> cnt1, cnt2;
        for (auto ch: word1) ++cnt1[ch];
        for (auto ch: word2) ++cnt2[ch];
        if (abs((int)(cnt1.size() - cnt2.size()))>2) return false;
        for (auto [ch1, c1]: cnt1){
            for (auto [ch2, c2]: cnt2){
                // try swap
                unordered_map<char, int> tmp1 = cnt1, tmp2 = cnt2;
                if (c1 == 1) tmp1.erase(ch1); else --tmp1[ch1];
                ++tmp1[ch2];
                if (c2 == 1) tmp2.erase(ch2); else --tmp2[ch2];
                ++tmp2[ch1];
                if (tmp1.size() == tmp2.size()) return true;
            }
        }
        return false;
    }
};
