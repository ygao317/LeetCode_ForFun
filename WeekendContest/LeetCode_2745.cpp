class Solution {
public:
    int longestString(int x, int y, int z) {
        return (((x == y) ? 2*x : (2 * min(x, y)+1))+z) * 2;
    }
};
