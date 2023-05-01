class Solution {
public:
    double average(vector<int>& salary) {
        int lmin = INT_MAX, lmax = INT_MIN;
        long long sum = 0;
        for (int s:salary){
            lmin = min(s, lmin);
            lmax = max(s, lmax);
            sum += s;
        }
        return (double)(sum - lmin - lmax) / (salary.size()-2);
    }
};
