class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int _lmax = 0, ans = 0;
        for (int i = prices.size()-1; i>=0; --i){
            _lmax = max(_lmax, prices[i]);
            ans = max(ans, _lmax-prices[i]);
        }
        return ans;
    }
};
