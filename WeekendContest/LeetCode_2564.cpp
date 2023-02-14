class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> mp;
        int i,j,n = s.length(),x;
        for(i = 0; i < s.length(); i++){
            x = 0;
            for(j = 0; i+j<s.length()&&j<32;j++){
                x = (x<<1)+(s[j+i]=='1');
                if(mp.count(x)==0){
                    mp[x].push_back(i);
                    mp[x].push_back(i+j);
                }
                if(s[i]=='0')break;
            }
        }
        vector<vector<int>> ans;
        for(auto &i: queries){
            if(mp.count(i[0]^i[1])){
                ans.push_back(mp[(i[0]^i[1])]);
            }else{
                ans.push_back({-1,-1});
            }
        }
        return ans;
    }
};