class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> v(26); 
        iota(v.begin(), v.end(), 0);
        function<int(int)> find = [&](int i) { return (v[i] == i) ? i : (v[i] = find(v[i]));  };
        
        int n = s1.size();
        for (int i=0; i<n; ++i){
            int i1 = find(s1[i] - 'a');
            int i2 = find(s2[i] - 'a');
            if (i1 > i2) swap(i1, i2);
            v[i2] = i1;
        }

        for (int i=0; i< baseStr.size(); ++i){
            int j = find(baseStr[i] - 'a');
            baseStr[i] = 'a' + j;
        }
        
        return baseStr;
    }
};
