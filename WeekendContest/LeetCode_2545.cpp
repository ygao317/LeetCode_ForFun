class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(), score.end(), [k](auto const & v1, auto const & v2){ return v1[k] > v2[k]; });
        return move(score);
    }
};
