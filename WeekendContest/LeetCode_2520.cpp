class Solution {
public:
    int countDigits(int num) {
        int ans = 0;
        int n = num;
        while (n){
            int d = n%10;
            if (d != 0 && num % d == 0) ++ans;
            n = n/10;
        }
        return ans;
    }
};
