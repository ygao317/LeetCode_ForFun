class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        auto ms = [=](int x){
            int a1 = x-2, b1 = (a1<=index) ? 1 : (a1-index+1), c1 = (a1<=index)? a1 : index;
            int a2 = x-1, b2 = (a2<=n-index) ? 1 : (a2-n+index+1), c2 = (a2<=n-index) ? a2 : n-index;
            return (((long long)a1+b1)*c1 + ((long long)a2+b2)*c2)/2 + n; 
        };
        int l = 1, r = maxSum+1;
        while (l < r){
            int m = l + (r-l)/2;
            if (ms(m)<=maxSum) l = m+1; else r=m;
        } 
        return l-1;
    }
};
