class Solution {
public:
    int countOrders(int n) {
        long long ans = 1, kmod = 1e9+7;
        for (int i = 0; i<n; ++i)
            ans = (ans * (2*i+1) * (i+1)) % kmod;
        return ans;
    }
};
