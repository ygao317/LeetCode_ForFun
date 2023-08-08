class Solution {
public:
    string finalString(string s) {
        string res;
        for (auto ch: s){
            if (ch == 'i') reverse(res.begin(), res.end());
            else res.push_back(ch);
        }
        return res;
    }
};
