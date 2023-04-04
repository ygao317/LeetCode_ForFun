class Solution {
public:
    int partitionString(string s) {
        set<char> ss;
        int ans = 0;
        for (char ch:s){
            if (ss.count(ch) != 0){ ss.clear(); ++ans; }
            ss.insert(ch);
        }
        return ans+1;
    }
};
