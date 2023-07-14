class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        int ans=0;
        unordered_map<int, int> cnt;
        for (int i=arr.size()-1; i>=0; --i)
            ans = max(ans, cnt[arr[i]]= cnt[arr[i]+d]+1);
        
        return ans;
    }
};
