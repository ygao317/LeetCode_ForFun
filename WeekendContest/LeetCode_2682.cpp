class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> fs(n, 0), ans;
        int pos = 0;
        for(int i=0; i<n; ++i){
            pos = (pos + i*k) % n;
            if (fs[pos] == 0) fs[pos] = 1; else break;
        }
        for (int i=0; i<n; ++i)
            if (fs[i] == 0) ans.push_back(i+1);
        return ans;
    }
};
