class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for (int sp: spells){
            auto itr = lower_bound(potions.begin(), potions.end(), (success+sp-1)/sp);
            ans.push_back(potions.end()-itr);
        }
        return ans;
    }
};
