class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        
        int d, f; 
        unordered_map<int, int> m;
        for (auto num: nums) ++m[num];
        for (auto& [k, v]: m){ if (v*2 > n){ d = k; f = v; break; }}
        
        int lc = 0;
        for (int i=0; i<n; ++i){
            if (nums[i] == d){
                ++lc;
                if (lc * 2 > i+1 && (f-lc)*2 > n-i-1) return i;
            }
        }
        return -1;
    }
};
