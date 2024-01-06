class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> seq;
        for (auto num: nums){
            auto itr = lower_bound(seq.begin(), seq.end(), num);
            if (itr == seq.end()) seq.push_back(num);
            else *itr = num;
        }
        return seq.size();
    }
};
