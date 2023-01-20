class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(begin(price), end(price));
        int l = 0, r = price.back() - price.front();
        while(l - r) {
            int m = (l + r + 1) / 2, cnt = 1;
            for (int i = 1, j = 0; i < price.size(); ++i)
                if (price[i] - price[j] >= m) {
                    ++cnt;
                    j = i;
                }
            if (cnt >= k)
                l = m;
            else
                r = m - 1;
        }
        return l;
    }
};
