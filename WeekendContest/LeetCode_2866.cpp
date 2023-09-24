class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        // two rounds
        int n = maxHeights.size();
        // left part
        vector<pair<int, int>> mh; mh.push_back({1, maxHeights[0]}); // {count, value}
        vector<long long> ls(n, 0L); ls[0] = maxHeights[0]; 
        for (int i=1; i<n; ++i){
            ls[i] = ls[i-1] + maxHeights[i];
            int c = 1;
            while (!mh.empty() && mh.back().second >= maxHeights[i]){
                auto [_c, _v] = mh.back(); mh.pop_back();
                c += _c; 
                ls[i] -= (long long)_c * (_v - maxHeights[i]);
            }
            mh.push_back({c, maxHeights[i]});
        }
        // right part => reuse mh
        long long ans = ls[n-1], rs = maxHeights[n-1]; mh.clear();
        mh.push_back({1, maxHeights[n-1]});
        for (int i=n-2; i>=0; --i){
            rs += maxHeights[i];
            int c = 1;
            while (!mh.empty() && mh.back().second >= maxHeights[i]){
                auto [_c, _v] = mh.back(); mh.pop_back();
                c += _c; 
                rs -= (long long)_c * (_v - maxHeights[i]);
            }
            mh.push_back({c, maxHeights[i]});
            ans = max(ans, rs + ls[i] - maxHeights[i]);
        }
        
        return ans; 
    }
};
