class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans; 
        for (auto& w: words){
            int l = 0, r = 0;
            for (; r < w.size(); ++r){
                if(w[r] == separator){
                    if (r > l) ans.push_back(w.substr(l, r-l));
                    l = r+1;
                }
            }
            if (r > l) ans.push_back(w.substr(l, r-l));
        }
        return ans;
    }
};
