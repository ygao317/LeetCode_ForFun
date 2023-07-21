class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int lmax = 0, lmin = 101;
        for (int n: nums){
            int tmp = n;
            if (n < lmin){ tmp = lmin; lmin = n; }
            if (n > lmax) { tmp = lmax; lmax = n; }
            if (tmp > lmin && tmp < lmax) return tmp;
        }
        return -1;
    }
};
