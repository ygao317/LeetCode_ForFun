class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int r = purchaseAmount % 10, d = purchaseAmount / 10 * 10;
        return (r<5)? (100-d) : (90-d);
    }
};
