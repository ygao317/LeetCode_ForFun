class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows == 1 || nRows == s.size()) return s;  // side scenario
        string ans; ans.reserve(s.length());
        int cycle = 2 * nRows - 2; //the size of a cycle(period)
        for(int i = 0; i < nRows; ++i)
        {
            for(int j = i; j < s.length(); j = j + cycle){
               ans.push_back(s[j]); // the first one will be there
               int secondJ = (j - i) + (cycle - i); // nice, start point + count (get from back) 
               if(i != 0 && i != nRows-1 && secondJ < s.length()) // not add if first/last
                   ans.push_back(s[secondJ]);
            }
        }
        return ans;
    }
};
