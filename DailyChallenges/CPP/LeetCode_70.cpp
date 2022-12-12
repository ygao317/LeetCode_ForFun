// 70. Climbing Stairs @ 2022/12/12
class Solution {
private:
    unordered_map<int, int> cache;
public:
    int climbStairs(int n) {
        if (cache[n] != 0) return cache[n];
        if ( n== 1 || n == 0) return (cache[n] = 1);
        return (cache[n] = climbStairs(n-1) + climbStairs(n-2));
    };
};
