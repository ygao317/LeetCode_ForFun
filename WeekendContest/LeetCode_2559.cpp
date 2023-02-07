class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<long long> cnt(n, 0L);
        string vol = "aeiou";
        for (int i = 0; i< n; ++i){
            bool isVol = find(vol.begin(), vol.end(), words[i].front()) != vol.end() && find(vol.begin(), vol.end(), words[i].back()) != vol.end();
            cnt[i] = ((i==0) ? 0 : cnt[i-1]) + ((isVol) ? 1 : 0);
        }
        
        vector<int> ans(queries.size(), 0);
        for (int i=0; i<queries.size(); ++i){
            int l = queries[i][0], r = queries[i][1];
            ans[i] = cnt[r] - ((l==0)?0:cnt[l-1]);
        }
        
        return ans;
    }
};
