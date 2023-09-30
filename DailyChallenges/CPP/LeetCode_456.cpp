class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> s;
        int rd = INT_MIN;
        for (int i= nums.size()-1; i>=0; --i){
            if (nums[i] < rd) return true;
            while (!s.empty() && s.back() < nums[i]){
                rd = s.back(); s.pop_back();
            }
            s.push_back(nums[i]);
        }
        return false;
    }
};
