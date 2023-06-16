class Solution {
public:
    vector<vector<long long>> pascal;   
    int mod = 1e9 + 7;
    
    long long dfs(vector<int> &nums){
        int n = nums.size();
        if(n <= 2) return 1;
        
        vector<int> left,right;
        
        for(int i = 1;i < n;i++)
            if(nums[i] > nums[0]) left.push_back(nums[i]); else right.push_back(nums[i]);
        
        long long left_res = dfs(left);
        long long right_res = dfs(right);
        
        int left_size = left.size() , right_size = right.size();
        
        return ((pascal[n - 1][left_size] * left_res)  % mod *right_res) % mod;
    }
    
    int numOfWays(vector<int>& nums){
        int n = nums.size();
        pascal.resize(n+1);
        
        // creating the pascal triangle
        for(int i = 0;i <= n;i++){
            pascal[i] = vector<long long>(i + 1,1);
            for(int j = 1 ;j < i; j++)
                pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i - 1][j]) % mod;
        }

        return dfs(nums) - 1;
    }
};
