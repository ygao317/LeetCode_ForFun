class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        unordered_map<int, unordered_map<int, int>> cnt;
        int res = 0;
        for (auto& c : coordinates) {
            for (int x = 0; x <= k; x++)
                if (cnt[c[0] ^ x].count(c[1] ^ (k - x)))
                    res += cnt[c[0] ^ x][c[1] ^ (k - x)];
            cnt[c[0]][c[1]]++;
        }
        return res;
    }
};
