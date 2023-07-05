class Solution {
public:
    int minLength(string s) {
       vector<char> stack;
       auto check = [&](){
           int sz = stack.size();
           if (sz < 2) return false;
           if (stack[sz-1] == 'B' && stack[sz-2] == 'A') return true;
           if (stack[sz-1] == 'D' && stack[sz-2] == 'C') return true;
           return false;
       };
       for (auto ch: s){
           stack.push_back(ch);
           while (check()){
               stack.resize(stack.size()-2);
           }
       } 
       return stack.size();
    }
};
