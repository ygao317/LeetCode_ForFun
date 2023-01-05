class Solution {
public:
    int similarPairs(vector<string>& words) {
        map<set<char>, int> m;
        int ans = 0;
        for (auto& w: words){
            set<char> s = set(w.begin(), w.end());
            ans += m[s];
            ++m[s];
        }
        return ans;
    }
};
