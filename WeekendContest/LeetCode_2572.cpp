using LL = long long;
class Solution {
    LL dp[1005][1025]; // (number, status)
    vector<int>primes = {2,3,5,7,11,13,17,19,23,29}; // 10 prime number, so 2 power 10 for status
    LL M = 1e9+7;
public:
    int squareFreeSubsets(vector<int>& nums) 
    {
        int n = nums.size();
        nums.insert(nums.begin(), 0); // add 0 to the front
        
        LL ret = 0;
        dp[0][0] = 1; // initiall status
        for (int i=1; i<=n; i++){ // 1 to n 
            int s = helper(nums[i]);
            for (int state = 0; state < (1<<10); state++)
            {
                if (nums[i]==1) // special case
                {
                    dp[i][state] = dp[i-1][state] * 2 % M;
                }
                else
                {
                    dp[i][state] = dp[i-1][state]; // not take number i                  
                    if (s!=-1 && (state&s)==s)                                        
                        dp[i][state] = (dp[i][state] + dp[i-1][state-s]) % M;                    
                }                                                
                if (i==n)
                    ret = (ret + dp[i][state]) % M;
            }
        }
        return (ret+M-1)%M;        
    }
    
    int helper(int x)
    {        
        int s = 0;
        for (int i=0; i<primes.size(); i++)
        {
            int count = 0;
            while (x%primes[i]==0)
            {
                count++;
                x/=primes[i];
            }
            if (count > 1)
                return -1;          
            else if (count==1)
                s += (1<<i);                    
        }
        return s;
    }
};
