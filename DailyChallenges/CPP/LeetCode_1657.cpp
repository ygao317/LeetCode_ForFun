// 1657. Determine if Two Strings Are Close @ 2022/12/02

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        if (n1 != n2) return false;
        
        unordered_map<char, int> cnt1, cnt2;
        for (auto ch: word1) ++cnt1[ch];
        for (auto ch: word2) ++cnt2[ch];
        
        if (cnt1.size() != cnt2.size()) return false;
        
        unordered_multiset<int> freq;
        unordered_set<char> keys;
        for (auto [k,v]: cnt1)
            freq.insert(v), keys.insert(k);
        for (auto [k,v]: cnt2){
            auto ptr = freq.find(v); 
            if (ptr == freq.end())
                return false;
            if (keys.find(k) == keys.end())
                return false;
            freq.erase(ptr);
        }
        return freq.empty();
    }
};
