class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if (k == 0) return (nums1 == nums2) ? 0 : -1;
        long long ans = 0L, sum = 0L;
        for (int i=0; i<nums1.size(); ++i){
            if (nums1[i]%k != nums2[i]%k) return -1;
            int l1 = nums1[i]/k, l2 = nums2[i]/k;
            if (l1 > l2) ans += l1 - l2;
            sum += l1 - l2;
        }
        return (sum == 0L) ? ans : -1;
    }
};
