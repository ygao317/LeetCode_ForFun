class Solution {
public:
    int countOdds(int low, int high) {
        int ans = (high - low) / 2;
        return (high%2 == 0 && low%2 == 0)? ans : (ans+1);
    }
};
