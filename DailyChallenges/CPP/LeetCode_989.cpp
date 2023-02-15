class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int i = num.size()-1, c = 0;
        while (k > 0 || i>=0 || c>0){
            c += k%10 + (i>=0 ? num[i--] : 0);
            ans.push_back(c%10);
            c /= 10; k /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
