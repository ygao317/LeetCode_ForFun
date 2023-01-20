class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size(), f = 0, b = 0;
        for (; f<=n/2; ++f)
            if (words[(startIndex+f)%n] == target) break;
        for (; b<=n/2; ++b)
            if (words[(startIndex-b+n)%n] == target) break;
        return (f == n/2+1 && b == n/2+1) ? -1 : min(f,b);
    }
};
