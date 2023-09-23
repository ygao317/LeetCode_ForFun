class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](auto& x, auto& y){ return x.size() < y.size(); });
        
        auto check = [](const string& x, const string& y){
            int j = 0, k = -1;
            for (int i=0; i < x.size(); ++i){
                if (x[i] != y[j++]) {
                    if (k != -1) return false; // not first time
                    if (x[i] != y[j++]) return false; // still not match 
                    k = j; 
                }
            }
            return true;
        };
        
        int n = words.size(), j = 0; 
        vector<int> v(n, 1);
        
        for (int i = 0; i<n-1; ++i){
            while (j<n && words[j].size() == words[i].size()) j++; // update j to next index.
            if (j==n) break;
            if (words[j].size() != words[i].size()+1){ i = j; continue; } // jump if break;
            
            for (int _j = j; _j<n && words[_j].size() == words[i].size()+1; _j++)
                if (check(words[i], words[_j]))
                    v[_j] = max(v[_j], v[i]+1);
        }

        return *max_element(v.begin(), v.end());
    }
};
