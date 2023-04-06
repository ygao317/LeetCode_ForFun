class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int t = 0; 
        for (int i = 0; i< reward1.size(); ++i){
            t += reward2[i];
            reward1[i] = reward2[i] - reward1[i];
        }
        sort(reward1.begin(), reward1.end());
        for (int i=0; i<k; ++i)
            t -= reward1[i];
        return t;
    }
};
