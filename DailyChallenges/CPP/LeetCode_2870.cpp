class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (auto num: nums) ++cnt[num];
        int ans = 0;
        for (auto& [_, c]: cnt){
            if (c==1) return -1;
            ans += c/3;
            if (c%3) ++ans;
        }
        return ans;
    }
};
