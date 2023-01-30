class Solution {
public:
    int cache[38] = {0};
    int tribonacci(int n) {
        if (n==0) return 0;
        if (cache[n] == 0){
            if (n == 1 || n == 2) 
                cache[n] = 1;
            else
                cache[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        }
        return cache[n];
    }
};
