class Solution {
public:
    int missingInteger(vector<int>& nums) {
        vector<int> cnt(51, 0); 
        for (auto n: nums) ++cnt[n];
        
        int m = nums[0];
        for (int i=1; i< nums.size(); ++i){
            if (nums[i] == nums[i-1]+1) m += nums[i]; else break;
        }
        
        while (m <=50 && cnt[m]) ++m;
        return m;
    }
};
