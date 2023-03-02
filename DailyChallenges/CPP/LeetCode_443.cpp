class Solution {
public:
    int compress(vector<char>& chars) {
        int cnt = 0;
        string s = "";
        for (auto ch: chars){
            if (ch == *s.rbegin()) ++cnt;
            else{
                if (cnt > 1) s = s + to_string(cnt);
                cnt = 1;
                s += ch;
            }
        }
        if (cnt>1) s += to_string(cnt);
        for (int i=0; i< s.length(); ++i)
            chars[i] = s[i];
        return s.length();
    }
};
