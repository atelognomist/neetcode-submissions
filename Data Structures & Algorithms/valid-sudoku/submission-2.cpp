class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        int r[9] = {}, c[9] = {}, x[9] = {};

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char v = b[i][j];

                if (v == '.') continue;

                int bit = 1 << (v - '1');
                int k = (i / 3) * 3 + j / 3;

                if ((r[i] | c[j] | x[k]) & bit)
                    return false;

                r[i] |= bit;
                c[j] |= bit;
                x[k] |= bit;
            }
        }

        return true;
    }
};