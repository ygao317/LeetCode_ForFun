static vector<int> primes; 

class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        if (primes.empty()){ // initiate the primes
            int n = 1005;
            vector<bool> isPrime(n, true);
            for(int i=2; i*i<n; i++)
                for(int j=2*i; j<n; j+=i)
                    isPrime[j] = false;
            for (int i=2; i<n; ++i)
                if (isPrime[i]) primes.push_back(i);
            //cout << primes.size() << " " << primes[0] << " " << primes[1] << " " << primes.back() << endl;
        }

        int pre = 0;
        for (int num: nums){
            if (num <= pre) return false;
            auto itr = lower_bound(primes.begin(), primes.end(), num - pre);
            pre = num - ((itr == primes.begin()) ? 0 : *(--itr));
        }
        return true;
    }
};
