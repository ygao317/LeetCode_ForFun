class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ts = 0, ls = 0, st=0;
        for (int i=0; i<gas.size(); ++i){
            ts += gas[i] - cost[i];
            ls += gas[i] - cost[i];
            if (ls < 0){
                ls = 0;
                st=i+1;
            }
        }
        return (ts < 0) ? -1 : st;
    }
};
