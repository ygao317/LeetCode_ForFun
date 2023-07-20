class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for (int a: asteroids){
            if (a < 0){
                while (!st.empty() && st.back() > 0 && a != 0){
                    int l = st.back();
                    if (a + l <= 0) st.pop_back();
                    if (a + l >= 0) a = 0;
                }
            }
            if (a != 0) st.push_back(a);
        }
        return st;
    }
};
