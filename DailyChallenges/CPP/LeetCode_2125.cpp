class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, p = 0;
        for (auto& r: bank){
            int c = 0;
            for (auto ch: r) if (ch == '1') ++c;
            if (c != 0){ ans += p * c; p = c;}
        }
        return ans;
    }
};
