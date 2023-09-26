class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26, -1);
        for (int i=0; i<s.size(); ++i) last[s[i]-'a'] = i;

        vector<int> taken(26, -1);
        string ans;
        for (int i=0; i<s.size(); ++i){
            if (taken[s[i]-'a'] == -1){
                while (!ans.empty() && ans.back() >= s[i] && i < last[ans.back()-'a']){
                    taken[ans.back()-'a'] = -1;
                    ans.pop_back();
                }
                taken[s[i]-'a'] = i; 
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
