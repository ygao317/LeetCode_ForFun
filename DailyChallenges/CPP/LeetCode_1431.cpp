class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = 0;
        for (auto c: candies) mx = max(mx, c);
        vector<bool> ans(candies.size(), false);
        for (int i=0; i<candies.size(); ++i)
            ans[i] = candies[i]+extraCandies >= mx;
        return ans; 
    }
};
