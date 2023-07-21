class Solution {
public:
    string smallestString(string s) {
        int l = -1, r = 0;
        for (; r < s.size(); ++r){
            if (l == -1){
                if(s[r] != 'a') l = r;
                else continue; 
            }
            if (s[r] == 'a') break;
            else
                s[r] -= 1;
        }
        if (l == -1){
            s.back() = 'z';
            return s;
        }
        
        return s;
    }
};
