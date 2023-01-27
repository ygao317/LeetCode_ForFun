class Solution {
public:
    int alternateDigitSum(int n) {
        int flip = 1, ans = 0;
        while(n){
            ans += flip * (n%10);
            n = n/10;
            flip = -flip;
        }
        return -flip * ans;
    }
};
