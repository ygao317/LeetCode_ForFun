// 2472. Maximum Number of Non-overlapping Palindrome Substrings

class Solution {
public:
    bool pal[2002][2002] = {};
    int maxPalindromes(string s, int k) {
        if (k == 1) return s.size(); // extreme case
        
        // first DP to get is palindrome from x to y
        for (int len = 1; len <= k + 1; ++len)
            for (int i = 0, j = i + len - 1; j < s.size(); ++i, ++j)
                pal[i][j] = (len < 3 ? true : pal[i + 1][j - 1]) && (s[i] == s[j]);
        
        // greedy (or can use another dp)
        int i = 0, res = 0;
        for (int i = 0; i + k <= s.size(); ++i) {
            res += pal[i][i + k - 1] || pal[i][i + k];
            i += pal[i][i + k - 1] ? k - 1 : (pal[i][i + k] ? k : 0);
        }
        return res;
    }
};
