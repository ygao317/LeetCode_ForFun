class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int ans = 0, n = words.size();
        vector<int> v(n);
        for (int i = 0; i<n; ++i){
            if (v[i]) continue;
            for (int j=i+1; j<n; ++j){
                if (v[j]) continue;
                if (words[i][0] == words[j][1] && words[i][1] == words[j][0]){
                    ++ans;
                    v[j] = 1;
                    break;
                }
            }
        }
        return ans;
    }
};
