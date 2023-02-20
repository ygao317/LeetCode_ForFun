class Solution {
public:
    int minMaxDifference(int num) {
        char c_max = 'a', c_min = 'a';
        string n_max = to_string(num), n_min = n_max;
        for (int i=0; i<n_max.size(); ++i){
            if (c_max == 'a' && n_max[i] != '9')
                c_max = n_max[i];
            if (n_max[i] == c_max) 
                n_max[i] = '9';

            if (c_min == 'a' && n_min[i] != '0')
                c_min = n_min[i];
            if (c_min == n_min[i])
                n_min[i] = '0';
        }
        return stoi(n_max) - stoi(n_min);
    }
};
