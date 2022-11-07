// 1323. Maximum 69 Number @ 2022/11/07

class Solution {
public:
    int maximum69Number (int num) {
        vector<int> vn;
        for (; num>0; num/=10)
            vn.push_back(num%10);
        
        reverse(begin(vn), end(vn));
        bool ch = false; int res = 0;
        for (auto i: vn){
            if (!ch && i == 6){
                ch = true; i=9;
            }
            res = res*10 + i;
        }
        
        return res;
    }
};
