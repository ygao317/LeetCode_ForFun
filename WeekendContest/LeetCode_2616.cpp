class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if (p==0) return 0;
        sort(nums.begin(), nums.end());
        
        function<bool(int)> check = [&](int mm) { // can achieve
            int cnt = 0;
            for (int i=0; i < nums.size()-1; ++i){
                if (nums[i+1] - nums[i] <= mm){
                    ++cnt; ++i;
                }
                if (cnt >= p) return true;
            }
            return false;
        };

        int l = 0, r = 1e9+1;
        while (l<r){
            int m = l + (r-l)/2;
            if (check(m)) r = m; else l = m+1;
        }
        return l;
    }
};
