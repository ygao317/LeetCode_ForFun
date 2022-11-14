// 2465. Number of Distinct Averages

class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        set<double> s;
        for (int i=0; i<n/2; ++i)
            s.insert((nums[i] + nums[n-1-i])/2.0);
        return s.size();
    }
};
