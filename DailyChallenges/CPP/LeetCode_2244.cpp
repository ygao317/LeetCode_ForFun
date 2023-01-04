class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> cnt;
        for (int t: tasks) 
            ++cnt[t];
        int ans = 0;
        for (auto [_, c]: cnt){
            if (c == 1) return -1;
            int d = c/3, r = c%3;
            if (r==0)
                ans += d;
            else // r == 1 or 2
                ans += d+1;
        }
        return ans;
    }
};
