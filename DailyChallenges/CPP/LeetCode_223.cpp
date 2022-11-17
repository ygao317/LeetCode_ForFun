// 223. Rectangle Area @ 2022/11/17

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        auto area = [](int x1, int x2, int y1, int y2) {
            return (x1<x2 && y1<y2) ? (x2-x1) * (y2-y1) : 0;
        };
        
        return area(ax1, ax2, ay1, ay2) + area(bx1, bx2, by1, by2) - 
            area(max(ax1,bx1), min(ax2,bx2), max(ay1,by1), min(ay2, by2));
    }
};
