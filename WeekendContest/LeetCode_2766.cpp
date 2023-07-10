class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        map<int, int> m;
        for (auto num: nums) ++m[num];
        for (int i = 0; i < moveFrom.size(); ++i){
            if(moveTo[i] == moveFrom[i]) continue;
            m[moveTo[i]] += m[moveFrom[i]];
            m.erase(moveFrom[i]);
        }
        vector<int> ans;
        for (auto& [k, _]: m) ans.push_back(k);
        return ans;
    }
};
