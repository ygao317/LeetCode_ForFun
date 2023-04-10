class Solution {
public:
    bool isPrime(int num) {
        if (num == 1) return false;
        for (int i = 2; i*i <= num; ++i) {
            if (num % i == 0)
                return false;
        }
        return true;
    }
    
    int diagonalPrime(vector<vector<int>>& nums) {
        int ans = 0, n = nums.size();
        for (int i = 0; i<n; ++i){
            if (nums[i][i]>ans && isPrime(nums[i][i])) ans = nums[i][i];
            if (nums[i][n-i-1]>ans && isPrime(nums[i][n-i-1])) ans = nums[i][n-i-1];
        }
        return ans;
    }
};
