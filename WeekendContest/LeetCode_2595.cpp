class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ans(2,0);
        bool even = true;
        while (n>0){
            if (n%2){
                if (even) ++ans[0]; else ++ans[1];
            }
            n = n/2;
            even = !even;
        }
        return ans;
    }
};
