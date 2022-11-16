// 2468. Split Message Based on Limit

class Solution {
public:
    vector<string> splitMessage(string message, int limit) {
        auto len = [](int num) { return to_string(num).size(); }; // lamda to get num length
        
        int il{0}, k{0}; // il is the total index number length 
        while (3 + len(k)*2 < limit && il + message.size() + (3+len(k))*k > limit*k)
        {
            ++k; 
            il += len(k);    
        }
        
        vector<string> ans;
        int i{0};
        if (3 + len(k)*2 < limit){
            for (int j=1; j <=k; ++j){
                int l = limit - (len(j) + 3 + len(k));
                ans.push_back(message.substr(i,l) + "<" + to_string(j) + "/" + to_string(k) + ">");
                i +=l;
            }
        }
        
        return ans;
    }
};
