class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> v(102, 0);
        for (auto& p: nums){
            v[p[0]]++; v[p[1]+1]--;
        }
        int ans = 0, lc = 0;
        for (int i = 1; i<101; ++i){
            lc += v[i];
            if (lc > 0) ans++;
        }
        return ans; 
    }
};
