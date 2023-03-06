class Solution {
public:
    int splitNum(int num) {
        vector<int> v;
        while (num > 0){
            v.push_back(num%10);
            num /= 10;
        }
        sort(v.begin(), v.end());
        int n[2] = {0};
        for (int i = 0; i<v.size(); ++i)
            n[i%2] = n[i%2] * 10 + v[i];
        return n[0] + n[1];
    }
};
