class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0;
        while (mainTank > 0){
            int taken = min(mainTank, 5);
            ans += taken * 10;
            mainTank -= taken;
            if (taken == 5 && additionalTank>0){
                mainTank++; additionalTank--;
            }
        }
        return ans;
    }
};
