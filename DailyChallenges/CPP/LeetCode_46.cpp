class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int mask = 0, n = nums.size(), end = (1<<n) -1;
        vector<vector<int>> res; vector<int> v;
        function<void()> dfs = [&](){
            if (mask == end) res.push_back(v);
            for (int i=0; i<n; ++i){
                int b = 1 << i;
                if (mask & b) continue;
                mask ^= b; v.push_back(nums[i]);
                dfs();
                v.pop_back(); mask ^= b;
            }
        };
        dfs();
        return res;
    }
};
