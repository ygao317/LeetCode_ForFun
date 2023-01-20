class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        vector<vector<int>> cnts;
        // forward first
        vector<int> cnt(3, 0);
        int i = 0;
        for (; i<n; ++i){
            if (all_of(cnt.begin(), cnt.end(), bind2nd(greater_equal<int>(),k))) break;
            ++cnt[s[i]-'a'];
            cnts.push_back(cnt);
        }

        if (any_of(cnt.begin(), cnt.end(), bind2nd(less<int>(),k)))
            return -1;
        
        int ans = i;
        cnt = {k, k, k};
        // backward to check
        for (int j=1; j<ans; ++j){
            if (cnt[s[n-j]-'a']>0) --cnt[s[n-j]-'a'];
            if (cnt[0] == 0 && cnt[1] == 0 && cnt[2] == 0) 
                ans = min(ans, j);
            else{
                auto itr = lower_bound(cnts.begin(), cnts.end(), cnt, 
                    [](auto & a, auto & b) { return a[0] < b[0] || a[1] < b[1] || a[2] < b[2];});
                ans = min(ans, j+(int)distance(cnts.begin(), itr)+1);
            }
        }
        return ans;
    };
};
