class Solution { 
public: 
    int makeTheIntegerZero(int num1, int num2) { 
        long long n = num1;
        int c = 0;
        while ((n -= num2) > 0){
            ++c;
            if (__builtin_popcountll(n) <= c && c <= n) return c;
        }
        return -1;
    }
};
