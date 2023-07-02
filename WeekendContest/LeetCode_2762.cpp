class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;
        int l = 0;
        map<int, int> m;
        for (int i=0; i< nums.size(); ++i){
            m[nums[i]]++;
            while(!(nums[i] <= m.begin()->first +2 && nums[i] >= m.rbegin()->first -2)){
                if (--m[nums[l]] == 0) m.erase(nums[l]);
                l++;
            }
            ans += i-l+1;
        }
        return ans;
    }
};
