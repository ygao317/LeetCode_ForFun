class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int n = nums.size();
        long long ans = (n%2 == 0)? 0 : nums[n/2];
        for (int i = 0; i<n/2; ++i){
            ans += stoi(to_string(nums[i]) + to_string(nums[n-1-i]));
        }
        return ans;
    }
};
