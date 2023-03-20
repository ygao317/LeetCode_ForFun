class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> rs(value+1, 0);
        for (int num: nums){
            int r = num % value;
            if (r<=0) ++rs[r+value]; else ++rs[r];
        }
        
        if (rs[value] == 0) return 0;
        rs[0] = rs[value]-1;
        int base = *min_element(rs.begin(), rs.end()-1);
        int ans = base * value;
        for (int i=1; i<value; ++i){
            if (rs[i] > base) 
                ++ans;
            else
                break;
        }
        return ans+1;
    }
};
