class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)    
    {
        auto itr = lower_bound(intervals.begin(), intervals.end(), newInterval);
        if (itr != intervals.begin()){ // beginning
            itr = prev(itr);
            if ((*itr)[1] >= newInterval[0]){
                newInterval[0] = (*itr)[0];
            } else {
                itr = next(itr);
            }
        }
        // ending
        while (itr != intervals.end() && (*itr)[0] <= newInterval[1]){
            if ((*itr)[1] > newInterval[1])
                newInterval[1] = (*itr)[1];
            itr = intervals.erase(itr); 
        }
        intervals.insert(itr, newInterval);
        return intervals;
    }
};
