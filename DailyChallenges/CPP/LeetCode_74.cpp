class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto itr_r = upper_bound(matrix.begin(), matrix.end(), vector<int>({target, INT_MAX}));
        if (itr_r == matrix.begin()) return false;
        itr_r = prev(itr_r);
        auto itr_c = lower_bound(itr_r->begin(), itr_r->end(), target);
        if (itr_c != itr_r->end() && *itr_c == target) return true; 
        return false; 
    }
};
