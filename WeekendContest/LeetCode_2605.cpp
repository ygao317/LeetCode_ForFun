class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
        for (auto n1: s1){
            if (s2.count(n1) > 0) return n1;
        }
        
        int n1 = *s1.begin(), n2 = *s2.begin();
        return (n1<n2) ? (n1*10+n2) : (n2*10 + n1);
    }
};
