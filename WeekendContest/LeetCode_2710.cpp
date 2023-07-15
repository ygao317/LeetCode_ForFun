class Solution {
public:
    string removeTrailingZeros(string num) {
        int n = num.size();
        while(num[n-1] == '0') --n;
        num.resize(n);
        return num;
    }
};
