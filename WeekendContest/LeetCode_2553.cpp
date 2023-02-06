class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int num: nums){
            for (auto c: to_string(num))
                ans.push_back(c-'0');
        }
        return ans;
    }
};
