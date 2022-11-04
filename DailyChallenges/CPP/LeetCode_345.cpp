// 345. Reverse Vowels of a String @ 2022/11/04

class Solution {
public:
    string reverseVowels(string s){
        const string vols = "aeiouAEIOU";
        int st = 0, ed = s.size()-1;
        
        while (st < ed){
            while (st<ed && vols.find(s[st]) == string::npos) ++st;
            while (ed>st && vols.find(s[ed]) == string::npos) --ed;
            if (st<ed) swap(s[st++],s[ed--]);
        }
        
        return s;
    }
};
