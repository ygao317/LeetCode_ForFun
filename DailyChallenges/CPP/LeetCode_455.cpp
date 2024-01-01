class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0, j = 0;
        for (auto k: g){
            while(j<s.size() && s[j] < k) ++j;
            if (j != s.size()) ++ans; else break;
            ++j;
        }
        return ans;
    }
};
