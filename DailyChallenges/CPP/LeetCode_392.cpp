class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j=0, n = t.size();
        for (int i=0; i<s.size(); ++i, ++j){
          while (j<n && s[i] != t[j]) j++;
          if (j == n) return false;
        }
        return true;
    }
};
