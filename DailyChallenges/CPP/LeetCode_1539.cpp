class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        arr.insert(arr.begin(), 0);
        for (int i = 1; i < arr.size(); ++i){
            int missing = arr[i] - arr[i-1] - 1;
            if (k > missing) 
                k -= missing; 
            else
                return arr[i-1] + k;
        }
        return arr.back() + k;
    }
};
