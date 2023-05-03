class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
        auto itr1 = s1.begin(), itr2 = s2.begin();
        while (itr1 != s1.end() || itr2 != s2.end()){
            if (itr1 == s1.end()){
                while (itr2 != s2.end()){
                    ans[1]. push_back(*itr2++);
                }
            } else if (itr2 == s2.end()){
                while (itr1 != s1.end()){
                    ans[0]. push_back(*itr1++);
                }
            } else if (*itr1 == *itr2){
                ++itr1; ++itr2;
            } else if (*itr1 < *itr2){
                ans[0].push_back(*itr1++);
            }else {
                ans[1].push_back(*itr2++);
            }
        }
        return ans;
    }
};
