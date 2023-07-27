class Solution {
public:
    int maxIncreasingGroups(vector<int>& A) {
        sort(A.begin(), A.end());
        long long total = 0, k = 0;
        for (int a : A) {
            total += a;
            if (total >= (k + 1) * (k + 2) / 2) // amazing, I reach this point here to figure out an efficient way to track it.....
                k++;
        }
        return k; 
    }
};
