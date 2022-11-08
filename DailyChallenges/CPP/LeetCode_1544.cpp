// 1544. Make The String Great @ 2022/11/08
class Solution {
public:
    string makeGood(string s) {
        string t;
        for (const auto & ch: s){
            if (!t.empty() && abs(t.back() - ch) == 32)
                t.pop_back();
            else
                t.push_back(ch);
        }
        return t;
    }
};
