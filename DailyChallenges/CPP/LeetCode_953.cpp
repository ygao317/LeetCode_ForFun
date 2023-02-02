class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int ord[26];
        for (int i=0; i<26; ++i) ord[order[i]-'a'] = i;
        
        function<bool(const string&, const string&)> cmp = [&](const string& w1, const string& w2){
            if (w1 == w2) return true;
            if (w1.size() > w2.size()) return !cmp(w2, w1);
            for (int i = 0; i< w1.size(); ++i){
                if (w1[i] == w2[i]) continue;
                return ord[w1[i]-'a'] < ord[w2[i]-'a'];
            }
            return true;
        };
        
        for (int i=1; i<words.size(); ++i){
            if (cmp(words[i-1], words[i])) continue;
            return false;
        }
        return true;
    }
};
