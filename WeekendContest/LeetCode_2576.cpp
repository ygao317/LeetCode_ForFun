class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        auto st = nums.begin();
        auto ed = lower_bound(nums.begin() + (nums.size()+1)/2, nums.end(), *st * 2);
        int ans = 0;

        while (ed != nums.end()){
            ans += 2;
            ++st; ++ed;
            while (ed < nums.end() && *ed < *st * 2)
                ++ed;
        }

        return ans;
    }
};
