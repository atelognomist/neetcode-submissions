class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        static constexpr int box[9][9] = {
            {0,0,0,1,1,1,2,2,2},
            {0,0,0,1,1,1,2,2,2},
            {0,0,0,1,1,1,2,2,2},
            {3,3,3,4,4,4,5,5,5},
            {3,3,3,4,4,4,5,5,5},
            {3,3,3,4,4,4,5,5,5},
            {6,6,6,7,7,7,8,8,8},
            {6,6,6,7,7,7,8,8,8},
            {6,6,6,7,7,7,8,8,8}
        };

        int rows[9] = {};
        int cols[9] = {};
        int boxes[9] = {};

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char v = b[i][j];

                if (v == '.') continue;

                int bit = 1 << (v - '1');
                int k = box[i][j];

                if ((rows[i] & bit) ||
                    (cols[j] & bit) ||
                    (boxes[k] & bit))
                    return false;

                rows[i] |= bit;
                cols[j] |= bit;
                boxes[k] |= bit;
            }
        }

        return true;
    }
};