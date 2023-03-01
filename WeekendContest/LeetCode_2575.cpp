class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        long long num = 0L;
        vector<int> ans(word.size(), 0);
        for (int i = 0; i < word.size(); ++i){
            num = num * 10 + (word[i]-'0');
            if (num % m == 0)
                ans[i] = 1;
            if (i % 5 == 0) num %= m;
        } 
        return ans;
    }
};
