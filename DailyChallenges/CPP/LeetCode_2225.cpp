// 2225. Find Players With Zero or One Losses @ 2022/11/28

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> wins, loses, moreLoses;
        for (auto& m:matches){
            wins.insert(m[0]);
            if (loses.find(m[1]) == loses.end()) loses.insert(m[1]); else moreLoses.insert(m[1]);
        }
        
        vector<int> rs1, rs2;
        set_difference(wins.begin(), wins.end(), loses.begin(), loses.end(), inserter(rs1, rs1.begin()));
        set_difference(loses.begin(), loses.end(), moreLoses.begin(), moreLoses.end(), inserter(rs2, rs2.begin()));
        return {rs1, rs2};
    }
};
