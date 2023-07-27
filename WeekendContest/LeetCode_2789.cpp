class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        vector<long long> stack;
        for (int i = nums.size()-1; i>=0; --i){
            long long num = nums[i];
            while (!stack.empty() && stack.back() >= num){
                num += stack.back();
                stack.pop_back();
            }
            stack.push_back(num);
        }
        return *max_element(stack.begin(), stack.end());
    }
};
