class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<long long> stack;
        for (auto &s: tokens){
            if (all_of(s.begin(), s.end(), ::isdigit) || (s[0] == '-' && s.size()>1))
                stack.push_back(stoi(s));
            else{
                int b = stack.back(); stack.pop_back();
                int a = stack.back(); stack.pop_back();
                if (s == "+")
                    stack.push_back(a+b);
                else if (s == "-")
                    stack.push_back(a-b);
                else if (s == "*")
                    stack.push_back((long long)a*b);
                else
                    stack.push_back(a/b);
            }
        }
        return stack.front();
    }
};
