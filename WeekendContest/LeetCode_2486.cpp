class Solution {
public:
    int appendCharacters(string s, string t) {
        auto i = s.find(t[0]); 
        int j = 0, n = t.size();
        while (i != string::npos && j < n)
            i = s.find(t[++j], i+1);
        return n-j;
    }
};
