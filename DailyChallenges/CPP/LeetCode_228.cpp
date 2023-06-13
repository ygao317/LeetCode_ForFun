class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) return {};
        vector<string> ans; 
        int st = nums[0];
        auto ps = [](int st, int ed){ return (st == ed) ? to_string(st) : (to_string(st) + "->" + to_string(ed)); };
        for (int i = 1; i < nums.size(); ++i){
            if (nums[i] != nums[i-1]+1){ 
                ans.push_back(ps(st, nums[i-1]));
                st = nums[i];
            }
        }
        ans.push_back(ps(st, nums.back()));
        return ans; 
    }
};
