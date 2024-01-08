class Solution {
public:
    int dp[10011] = {};
    int minimumOperationsToMakeEqual(int x, int y) {
        if (x <= y)
            return y - x; // # 4
        if (dp[x] == 0)
            dp[x] = 1 + min({
                minimumOperationsToMakeEqual(x / 11 + (x % 11 > 0), y) + (11 - x % 11) % 11, // #1 (+ #4)
                minimumOperationsToMakeEqual(x /  5 + (x %  5 > 0), y) + ( 5 - x %  5) %  5, // #2 (+ #4)
                minimumOperationsToMakeEqual(x - 1, y) // # 3
            });
        return dp[x];
    }
};
