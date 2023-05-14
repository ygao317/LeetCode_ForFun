class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int z = 0, o = 1;
        for (int d: derived){
            z ^= d;
            o ^= d;
        }
        return z == 0 || o == 1;    
    }
};
