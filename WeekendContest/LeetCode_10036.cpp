class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if (a == e && !(c == a && (d-b)*(d-f)<0)) return 1;
        if (b == f && !(d == b && (c-a)*(c-e)<0)) return 1;
        if (c-e == d-f && !(a-c == b-d && (a-c)*(a-e)<0)) return 1;
        if (c-e == f-d && !(a-c == d-b && (a-c)*(a-e)<0)) return 1;
        return 2;
    }
};
