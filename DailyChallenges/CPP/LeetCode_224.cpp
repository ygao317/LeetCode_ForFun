// 224. Basic Calculator @ 2022/11/20

class Solution {
public:
    int calculate(string s) {
      int res = 0, num = 0, sign = 1; 
      stack<int> stk;
      for(int i = 0; i < s.size(); ++i) {
         while(i < s.size() && isdigit(s[i])) {
           num = num * 10 + (s[i] - '0');
           ++i;
         }
         res += (num * sign);
         num = 0;
         if(s[i] == '+') {
            sign = 1;
         }else if( s[i] == '-') {
            sign = - 1;
         }else if(s[i] == '(') {
            stk.push(res);
            res = 0;
            stk.push(sign);
            sign = 1;
         }else if(s[i] == ')') {
            res *= stk.top();
            stk.pop();
            res += stk.top();
            stk.pop();
        }
      }
      return res;
    }
};
