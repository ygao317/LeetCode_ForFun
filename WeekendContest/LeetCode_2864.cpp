class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int c = 0;
        for (auto ch:s)
            if (ch == '1') ++c;
        
        string ans(s.size(), '0'); ans[s.size()-1] = '1';
        for (int i=0; i<c-1; ++i) ans[i] = '1';
        return ans; 
    }
};
