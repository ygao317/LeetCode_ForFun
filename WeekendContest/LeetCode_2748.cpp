class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int ans = 0, n = nums.size();
        vector<pair<int, int>> ds(n);
        for (int i=0; i<n; ++i){
            auto str = to_string(nums[i]); 
            ds[i] = {str[0]-'0', str.back()-'0'};
        }
        
        for (int i=0; i<n; ++i)
            for (int j=i+1; j<n; ++j)
                if(gcd(ds[i].first,ds[j].second) == 1) ans++;
        
        return ans;
    }
};
