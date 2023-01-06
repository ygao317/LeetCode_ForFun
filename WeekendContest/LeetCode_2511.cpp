class Solution {
public:
    int captureForts(vector<int>& forts) {
        // 1 0 0 0 -1 or -1 0 0 0 1
        int ans = 0, start = -1, sd = 0;
        for (int i=0; i<forts.size(); ++i){
            if (forts[i] != 0){
                if (start != -1 && sd == -forts[i]) // good pattern
                    ans = max(ans, i-start-1);
                start = i, sd = forts[i];
            } else {
                if (i > start+1 && forts[i-1] != 0) start = -1;
            }
        }
        return ans;
    }
};
