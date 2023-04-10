class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> res(n);
        unordered_map<int, long long> sum_l, sum_r, cnt_l, cnt_r;    
        for (int i = 0; i < n; ++i) { // from left to right
            res[i] = cnt_l[nums[i]] * i - sum_l[nums[i]];
            sum_l[nums[i]] += i;
            ++cnt_l[nums[i]];
        }  
        for (int i = n-1; i >= 0; --i) { // from right to left 
            res[i] += sum_r[nums[i]] - cnt_r[nums[i]] * i;
            sum_r[nums[i]] += i;
            ++cnt_r[nums[i]];
        }
        return res;
    }
};
