class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> cnt;
        int ans = 0, l = 0, r = 0;
        while (r < fruits.size()){
            ++cnt[fruits[r++]];
            while(cnt.size() > 2) {
                if (--cnt[fruits[l]] == 0)
                    cnt.erase(fruits[l]);
                ++l;
            }
            ans = max(ans, r-l);
        }
        return ans;
    }
};
