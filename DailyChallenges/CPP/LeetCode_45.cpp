class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int ans = 1, l = 0, r = nums[0];
        while (r < n-1){
            int _l = l, _r = r; // old value
            while (++_l <= _r){
                if (_l + nums[_l] > r){
                    l = _l;
                    r = l + nums[l];
                }
            }
            ++ans;
        }
        return ans;
    }
};
