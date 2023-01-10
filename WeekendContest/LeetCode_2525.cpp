class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool bulky = length >=10000 || width >= 10000 || height >= 10000 || static_cast<long long>(length) * width * height >= 1e9;
        bool heavy = mass >= 100;
        if (bulky && heavy) return "Both";
        if (!bulky && !heavy) return "Neither";
        if (bulky) return "Bulky";
        return "Heavy";
    }
};
