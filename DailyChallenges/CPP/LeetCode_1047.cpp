// 1047. Remove All Adjacent Duplicates In String @ 2022/11/10

class Solution {
public:
    string removeDuplicates(string s) {
        string t; 
        for (const auto& ch:s){
            if (!t.empty() && t.back() == ch)
                t.pop_back();
            else
                t.push_back(ch);
        }
        return t;
    }
};
