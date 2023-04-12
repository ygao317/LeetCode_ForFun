class Solution {
public:
    string simplifyPath(string path) {
        vector<string> s;
        size_t st = 0;
        while (true) {
            auto ed = path.find("/", st);
            string p = path.substr(st,((ed == string::npos) ? path.size() : ed)-st);
            if(!s.empty() && p == "..") s.pop_back();
            else if(p != "" && p != "." && p != "..") s.push_back(p);
            if (ed == string::npos) break;
            st = ed+1;
        }
        if(s.empty()) return "/";

        string ans;
        for (auto& str: s) ans += "/" + str;
        
        return ans;
    }
};
