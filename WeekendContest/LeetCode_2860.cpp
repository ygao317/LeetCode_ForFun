class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = ((nums[0]>0)?1:0), n = nums.size();
        for (int i=0; i<n; ++i)
            if (nums[i]< i+1 && (i==n-1 || nums[i+1] > i+1)){
                //cout << i << endl;
                ++ans;
            } 
        
        return ans;
    }
};
