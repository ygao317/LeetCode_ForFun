// 739. Daily Temperatures @ 2022/12/18
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // max stack
        vector<int> ans(temperatures.size(), 0);
        vector<int> stack; stack.push_back(0);
        for (int i = 1; i<temperatures.size(); ++i){
            while (!stack.empty() && temperatures[stack.back()] < temperatures[i]){
                ans[stack.back()] = i - stack.back();
                stack.pop_back();
            }
            stack.push_back(i);
        }
        return ans;
    }
};
