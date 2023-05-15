class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> cnt(101, 0);
        for (int i=0; i<k; ++i) ++cnt[nums[i]+50];
        
        auto get = [&](){
            int c = 0;
            for (int i=0; i<50; ++i){
                c += cnt[i];
                if (c>=x) return i-50;
            }
            return 0;
        };
        vector<int> ans(nums.size()-k+1, 0); ans[0] = get();
        for (int i=k; i<nums.size(); ++i){
            ++cnt[nums[i]+50]; 
            --cnt[nums[i-k]+50];
            ans[i-k+1] = get();
        }
        return ans;
    }
};
