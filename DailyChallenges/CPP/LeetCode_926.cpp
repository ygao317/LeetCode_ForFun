class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> flip_0(n+1); // 1 to n
        for (int i=1; i<=n; ++i)
            flip_0[i] = flip_0[i-1] + ((s[i-1] == '0') ? 0 : 1);

        int ans = flip_0[n]; // all flip to 0
        int flip_1 = 0;
        for (int i = n-1; i>=0; --i){
            flip_1 += (s[i] == '1') ? 0 : 1;
            ans = min(ans, flip_1 + flip_0[i]);
        }

        return ans;
    }
};
