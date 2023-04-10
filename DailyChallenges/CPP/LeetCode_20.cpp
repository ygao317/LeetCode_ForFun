class Solution {
public:
    bool isValid(string s) {
        vector<char> v;
        for (auto ch:s){
            if ((ch == ')' && (!v.empty() && v.back() == '(')) ||
                (ch == ']' && (!v.empty() && v.back() == '[')) ||
                (ch == '}' && (!v.empty() && v.back() == '{'))){
                v.pop_back();
                continue;
            }
            if (ch == '(' || ch == '[' || ch == '{'){
                v.push_back(ch);
                continue;
            }
            return false;
        }
        return v.empty();
    }
};
