class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size(), ans = 0;
        for (int i = 1; i<n; ++i){
            ans = max(ans, stones[i] - ((i>1)? stones[i-2] : 0));
        }
        return ans;
    }
};
