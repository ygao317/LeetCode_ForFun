class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> ips;
        function<void(vector<int>&, int)> dfs = [&](vector<int>& v, int i){
            if (v.size()>4) return;
            if (i==n) { // reach the end
                if (v.size() != 4) return;
                string ip = accumulate(next(v.begin()), v.end(), to_string(v[0]), 
                    [](string a, int b) { return a + '.' + to_string(b);});
                ips.push_back(ip);
                return;
            }
            int digit = s[i] - '0';
            // possible to add another
            if (v.size()<4){
                v.push_back(digit);
                dfs(v, i+1);
                v.pop_back();
            }
            // or add to last one
            int seg = v.back() * 10 + digit;
            if (seg <= 255 && v.back() != 0){
                v.pop_back(); v.push_back(seg);
                dfs(v, i+1);
                v.pop_back(); v.push_back(seg/10);
            }
        };

        vector<int> v = {s[0]-'0'};
        dfs(v, 1);
        
        return ips;
    }
};
