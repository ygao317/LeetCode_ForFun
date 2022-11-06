// 899. Orderly Queue @ 2022/11/6

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k>1){
            sort(begin(s), end(s));
            return s;
        } else {
            string t = s; 
            for (int i = 0; i < s.size(); ++i){
                rotate(begin(s), begin(s)+1, end(s));
                t = min(t,s);
            }
            return t;
        }
    }
};
