// 1235. Maximum Profit in Job Scheduling @ 2022/11/26

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        for (int i = 0; i < n; ++i) 
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        
        sort(jobs.begin(), jobs.end()); // end time, start time, profit
        map<int, int> dp = {{0, 0}}; // till the end time, profit
        for (auto& job : jobs) {
            int cur = prev(dp.upper_bound(job[1]))->second + job[2];
            if (cur > dp.rbegin()->second)
                dp[job[0]] = cur;
        }
        return dp.rbegin()->second;
    }
};
