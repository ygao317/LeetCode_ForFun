class Solution {
public:
    string sortVowels(string s) {
        string vols = "AEIOUaeiou"; 
        vector<int> idx;
        string vs;
        for (int i=0; i<s.size(); ++i){
            if (vols.find(s[i]) != string::npos){
                idx.push_back(i); vs.push_back(s[i]);
            }
        }
        sort(vs.begin(), vs.end());
        for (int i=0; i<idx.size(); ++i){
            s[idx[i]] = vs[i];
        }
        return s;
    }
};
