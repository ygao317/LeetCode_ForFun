class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        // two rounds
        int n = maxHeights.size();
        // left part
        vector<int> mh(n, 0); mh[0] = maxHeights[0];
        vector<long long> ls(n, 0L); ls[0] = maxHeights[0]; 
        for (int i=1; i<n; ++i){
            ls[i] = ls[i-1] + maxHeights[i];
            mh[i] = maxHeights[i];
            for (int j = i-1; j>=0 && mh[j] > mh[j+1]; --j){
                ls[i] -= mh[j] - mh[j+1];
                mh[j] = mh[j+1];
            }
        }
        // right part => reuse mh,
        long long ans = ls[n-1], rs = maxHeights[n-1];
        mh[n-1] = maxHeights[n-1];
        for (int i=n-2; i>=0; --i){
            rs += maxHeights[i];
            mh[i] = maxHeights[i];
            for (int j = i+1; j<n && mh[j] > mh[j-1]; ++j){
                rs -= mh[j] - mh[j-1];
                mh[j] = mh[j-1];
            }
            ans = max(ans, rs + ls[i] - maxHeights[i]);
        }
        
        return ans; 
    }
};
