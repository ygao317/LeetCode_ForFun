class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        
        int ans = -1;
        auto itr = s.begin();
        while(itr != s.end()){
            int count = 1;
            auto ptr = itr; 
            int p = *ptr;
            if (p > sqrt(100000)) break;
            while ((ptr = s.find(p * p)) != s.end()){
                ++count;
                p = *ptr;
                s.erase(ptr);
                if (p > sqrt(100000)) break;
            }
            if (count > 1) ans = max(ans, count);
            ++itr;
        }
        
        return ans;
    }
};
