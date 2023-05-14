class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for (auto& p: details)
            if ((p[11]-'0')*10 + (p[12]-'0') > 60) 
                ++ans;
        return ans;
    }
};
