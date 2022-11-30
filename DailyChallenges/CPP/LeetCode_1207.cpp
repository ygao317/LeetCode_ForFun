// 1207. Unique Number of Occurrences @ 2022/11/30

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (auto i: arr)
            ++cnt[i];
        unordered_set<int> ck;
        for (auto [_, v]: cnt)
            if (ck.find(v) == ck.end()) 
                ck.insert(v);
            else
                return false;
        return true;
    }
};
