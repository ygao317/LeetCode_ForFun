class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size(), h = 0;
        vector<int> l(k+1, 0); // + first, - back
        for (int i = 0; i < n; ++i){
            h += l[i%(k+1)]; l[i%(k+1)] = 0;
            if (h == nums[i]) continue;
            if (h > nums[i] || i+k>n) return false;
            if (h < nums[i]){
                l[(i+k)%(k+1)] = h - nums[i];
                h = nums[i];
            }
        }
        return true;
    }
};
