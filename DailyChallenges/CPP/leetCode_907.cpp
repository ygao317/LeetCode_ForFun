// 907. Sum of Subarray Minimums @ 2022/11/25

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> l(n, -1), stack;
        for (int i=0; i<n; ++i){
            while (!stack.empty() && arr[stack.back()]>arr[i])
                stack.pop_back();
            l[i] = (stack.empty()) ? (i+1) : (i-stack.back());
            stack.push_back(i);
        }
        
        long ans = 0L;
        stack.clear(); 
        for (int i=n-1; i>=0; --i){
            while (!stack.empty() && arr[stack.back()]>=arr[i])
                stack.pop_back();
            long r = (stack.empty()) ? (n-i) : (stack.back()-i);
            stack.push_back(i);
            ans = (ans + l[i]*r*arr[i]) % 1000000007;
        }
            
        return ans;
    }
};
