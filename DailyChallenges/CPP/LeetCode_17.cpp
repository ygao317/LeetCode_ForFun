class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> dict = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res; res.push_back("");
        for (char d: digits){
            vector<string> tmp;
            for (auto ch: dict[(d-'2')]){
                for (auto& s: res){
                    tmp.push_back(s);
                    tmp.back().push_back(ch);
                }
            }
            tmp.swap(res);
        }
        if (res.size() == 1) res = {};
        return res;
    }
};
