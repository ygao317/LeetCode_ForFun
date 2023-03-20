class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) return -1;
        if (money > children * 8) return children-1;
        int _m = money - children; // each got 1 dollar first.
        int ans = _m / 7; // how many 7
        return (_m % 7 == 3 && ans == children-1)? (ans-1): ans; 
    }
};
