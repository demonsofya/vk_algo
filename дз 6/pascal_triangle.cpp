// leetcode https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v{{1}};
        v.reserve(numRows);

        for (int i = 1; i < numRows; i++) {
            v.emplace_back(i + 1, 1);
            
            for (int j = 1; j < i; j++) {
                v[i][j] = v[i-1][j-1] + v[i-1][j];
            }
        }

        return v;
    }
};
