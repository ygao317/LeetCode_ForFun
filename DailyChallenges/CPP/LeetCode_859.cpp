class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;
        if (s == goal){
            vector<int> v(26);
            for(auto ch: s)
                if ( ++v[ch-'a'] > 1) return true;
            return false;
        } else {
            vector<pair<int, int>> ps;
            for (int i = 0; i < s.size(); ++i){
                if (s[i] != goal[i]){
                    ps.push_back({s[i], goal[i]});
                    if (ps.size() == 3) return false;
                }
            }
            if (ps.size() < 2) return false;
            return ps[0].first == ps[1].second && ps[1].first == ps[0].second; 
        }
    }
};
