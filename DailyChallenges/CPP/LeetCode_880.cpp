class Solution {
public:
    string decodeAtIndex(string s, int k) {
        // need a stack
        vector<pair<string, int>> stack; // { post, base size}
        
        string str = ""; long long cnt = 0L;
        for (auto ch: s){
            if (ch >='a' && ch <= 'z'){
                str.push_back(ch);
                ++cnt;
            }else{
                stack.push_back({str, cnt});
                cnt *= ch-'0'; 
                str = "";
                if (cnt >= k) break; 
            }
        }
        if (str != "") stack.push_back({str, cnt});

        while(!stack.empty()){
            auto [str, cnt] = stack.back(); stack.pop_back();
            k = (k-1)%cnt + 1;
            if (cnt-k < str.size())
                return { str[str.size() + k - cnt -1] };
        }
        return "";
    }
};
