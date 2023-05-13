class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int s1 = player1[0], s2 = player2[0];
        for (int i=1; i< player1.size(); ++i)
            s1 += (player1[i-1] == 10 || (i-2 >=0 && player1[i-2] == 10)) ? (player1[i] * 2) : player1[i];
        for (int i=1; i< player2.size(); ++i)
            s2 += (player2[i-1] == 10 || (i-2 >=0 && player2[i-2] == 10)) ? (player2[i] * 2) : player2[i];
        if (s1 > s2) return 1;
        else if (s1 < s2) return 2; 
        else return 0;
    }
};
