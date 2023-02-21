class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        for (; i< nums1.size() && j < nums2.size();){
            int l = nums1[i][0], r = nums2[j][0];
            if (l == r)
                ans.push_back({l, nums1[i++][1] + nums2[j++][1]});
            else if (l < r)
                ans.push_back(nums1[i++]);
            else
                ans.push_back(nums2[j++]);
        }
        for (; i < nums1.size(); ++i)
            ans.push_back(nums1[i]);
        for (; j < nums2.size(); ++j)
            ans.push_back(nums2[j]);
        return ans;
    }
};
