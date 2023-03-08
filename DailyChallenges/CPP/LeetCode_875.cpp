class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto check = [&](int k){
            int _h = 0;
            for (int p: piles){
                _h += (p+k-1)/k;
                if (_h > h) return true;
            }
            return false;
        };
        int l = 1, r = 1e9;
        while (l < r){
            int m = l + (r-l)/2;
            if (check(m)) l = m+1; else r=m;
        }
        return l;
    }
};
