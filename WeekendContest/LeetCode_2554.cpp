class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int> ban(banned.begin(), banned.end());
        int sum = 0, cnt = 0;
        for (int i = 1; i <=min(n, maxSum); ++i){
            if (ban.find(i) != ban.end()) continue;
            sum += i;
            if (sum > maxSum) break;
            cnt++;
        }
        return cnt;
    }
};
