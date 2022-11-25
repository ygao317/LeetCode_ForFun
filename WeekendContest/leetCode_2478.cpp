// 2478. Number of Beautiful Partitions @ 2011/11/25

class Solution {
    long dp[1001][1001];
    bool isprime(char ch){ return ch == '2' || ch == '3' || ch == '5' || ch == '7'; }
public:
    int beautifulPartitions(string s, int k, int minLength) 
    {
        int n = s.size();
        s = "#"+s;
        
        dp[0][0] = 1;
        for (int j=1; j<=k; j++){
            long sum = 0;
            for (int i=1; i<=n; i++)            
            {    
                if (i-minLength>=0 && !isprime(s[i-minLength]) && isprime(s[i-minLength+1]))
                    sum = (sum + dp[i-minLength][j-1]) % 1000000007;
                    
                if (!isprime(s[i])) 
                    dp[i][j] = sum;                    
            }
        }
    
        return dp[n][k];
    }
};
