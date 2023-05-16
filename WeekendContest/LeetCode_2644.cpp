class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        unordered_set<int> cache;
        vector<int> ans = {INT_MAX, -1};
        for (int d: divisors){
            if (cache.count(d) > 0) continue;
            cache.insert(d);
            int lc = 0;
            for (int num: nums)
                if (num%d == 0) ++lc;
            if (lc > ans[1] || (lc == ans[1] && d < ans[0])) ans = {d,lc};
        }
        return ans[0];
    }
};
