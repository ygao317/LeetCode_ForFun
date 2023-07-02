class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        auto isPrime = [](int x) {
            for (int k = 2; k <= sqrt(x); ++k)
                if (x%k == 0) return false;
            return true;
        };
        
        if (n < 4) return {};
        if (n == 4) return {{2,2}};
        
        vector<vector<int>> ans;
        if (n % 2 == 1){
            if (isPrime(n-2)) ans.push_back({2, n-2});
        } else {
            for (int i = 3; i <= n/2; i+=2){
                if (isPrime(i) && isPrime(n-i)) ans.push_back({i, n-i});
            }
        }
        return ans;
    }
};
