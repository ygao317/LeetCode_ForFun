class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        map<int, int> cnt;
        for (int num: nums) ++cnt[num];
        int left = 0, ans = 0;
        for (auto [_, c]: cnt){
            int matched = min(left, c);
            ans += matched;
            left = left - matched + c;
        }
        return ans;
    }
};
