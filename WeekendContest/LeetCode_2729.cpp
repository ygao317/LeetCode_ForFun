class Solution {
public:
    bool isFascinating(int n) {
        string s = to_string(n) + to_string(2*n) + to_string(3*n);
        if (s.size() > 9) return false;
        vector<int> cnt(10, 0);
        for (int i=0; i< s.size(); ++i){
            int d = s[i]-'0';
            if (d==0 || cnt[d]>0) return false;
            ++cnt[d];
        }
        return true;
    }
};
