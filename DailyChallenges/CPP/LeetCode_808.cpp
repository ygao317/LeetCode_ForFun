class Solution {
public:
    double soupServings(int n) {
        n = (n+24)/25;
        if (n >= 200) return 1.;
        double dp[200][200];
        
        function<double(int, int)> f = [&](int a, int b){
            if (a<= 0 && b <=0) return 0.5;
            if (a<= 0) return 1.0;
            if (b<= 0) return 0.0;
            if (dp[a][b]) return dp[a][b];
            return dp[a][b] = 0.25 * (f(a-4, b) + f(a-3,b-1)+ f(a-2, b-2) + f(a-1, b-3));
        };
        
        return f(n, n);
    }
};
