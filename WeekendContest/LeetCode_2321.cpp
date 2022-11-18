// 2321. Maximum Score Of Spliced Array

class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        auto kadane = [](vector<int>& v1, vector<int>& v2) {
            int res{0}, cur{0}, sum2{0};
            for (int i=0; i< v1.size(); ++i){
                cur = max(0, cur + v1[i] - v2[i]);
                res = max(res, cur);
                sum2 += v2[i];
            }
            return res + sum2;
        };
        return max(kadane(nums1, nums2), kadane(nums2, nums1));
    }
};
