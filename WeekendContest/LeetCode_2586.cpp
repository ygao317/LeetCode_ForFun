class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        auto v = set({'a', 'e', 'i', 'o', 'u'});
        int ans = 0;
        for (int i= left; i <=right; ++i)
            if (v.count(words[i].front()) && v.count(words[i].back())) ++ans;
        return ans;
    }
};
