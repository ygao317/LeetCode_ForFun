// 263. Ugly Number @ 2022/11/18

class Solution {
public:
    bool isUgly(int n) {
        for (int p: {2,3,5})
            while (n%p == 0 && n>0)
                n /= p;
        return n == 1;
    }
};
