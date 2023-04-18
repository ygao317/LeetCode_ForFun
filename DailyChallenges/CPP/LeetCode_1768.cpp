class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        int n = min(n1, n2);
        string ans;
        for (int i=0; i < n; ++i){
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
        }
        return ans + ((n1<n2)? word2.substr(n, n2) : word1.substr(n,n1));
    }
};
