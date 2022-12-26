class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false); visited[0] = true;
        for (int i=0; i<n; ++i){
            if (visited[i])
                fill_n(visited.begin() + i + 1, min(n-i-1, nums[i]), true);
            if (visited[n-1]) return true;
        }
        return false;
    }
};
