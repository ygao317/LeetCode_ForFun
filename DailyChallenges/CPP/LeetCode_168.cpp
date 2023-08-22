class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n > 0) {
            int r = n % 26;
            if (r == 0) {
                res.push_back('Z');
                n -= 1;
            } else 
                res.push_back('A' + r - 1);
            n /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
