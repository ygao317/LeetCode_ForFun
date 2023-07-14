class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> rec(n+1, n+1); rec[n] = 0;
        function<int(int)> dfs = [&](int pos){
            if (rec[pos] < n+1) return rec[pos];
            rec[pos] = n-pos;
            for (auto& sub: dictionary){
                auto _pos = s.find(sub, pos);
                if (_pos != string::npos && _pos - pos < rec[pos]){
                    int _r = (_pos - pos) + dfs(_pos+sub.size());
                    rec[pos] = min(rec[pos], _r);
                }
            }
            return rec[pos];
        };
        return dfs(0);
    }
};
