class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        auto getKey = [&](int i){ string s = {words[i][0], words[i].back()}; return s;};
        unordered_map<string, int> m; m[getKey(0)] = words[0].size();
        for (int i = 1; i< words.size(); ++i){
            string key = getKey(i); int value = words[i].size();
            unordered_map<string, int> tmp;
            for (auto& [k, v]: m){
                //cout << key << " " << value << " " << k << " " << v << endl;
                string k1 = {k[0], key[1]};
                auto v1 = v + value - (k[1] == key[0] ? 1 : 0);
                tmp[k1] = (tmp[k1] == 0) ? v1 : min(tmp[k1], v1);
                string k2 = {key[0], k[1]};
                auto v2 = v + value - (k[0] == key[1] ? 1 : 0);
                tmp[k2] = (tmp[k2] == 0) ? v2 : min(tmp[k2], v2);
            }
            m.swap(tmp);
        }
        int ans = INT_MAX;
        for (auto & [k,v]: m)
            ans = min(ans, v);
        return ans;
    }
};
