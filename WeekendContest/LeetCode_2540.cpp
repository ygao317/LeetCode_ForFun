class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i1 = 0, i2 = 0, n1 = nums1.size(), n2 = nums2.size();
        while (i1 < n1 && i2 < n2){
            if (nums1[i1] == nums2[i2]) return nums1[i1];
            if (nums1[i1] < nums2[i2]) i1++;
            if (nums1[i1] > nums2[i2]) i2++;
        }
        return -1;
    }
};
