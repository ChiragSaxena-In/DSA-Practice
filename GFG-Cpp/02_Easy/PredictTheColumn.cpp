#include <vector>
using namespace std;
/*
=========================================================
Column With Maximum Zeros
=========================================================

Definition:
Return index of the column that contains
maximum number of zeros in a binary matrix.

If no zeros exist, return -1.

Approach:
- Traverse column-wise.
- Count zeros in each column.
- Track maximum zero count and index.

Time Complexity: O(N * N)
Space Complexity: O(1)
=========================================================
*/

class Solution {
public:
    int columnWithMaxZeros(vector<vector<int>> mat, int N) {
        
        int result = -1;
        int maxZeros = 0;
        
        int rows = mat.size();
        int cols = mat[0].size();
        
        // Traverse each column
        for (int col = 0; col < cols; col++) {
            
            int zeroCount = 0;
            
            // Count zeros in current column
            for (int row = 0; row < rows; row++) {
                if (mat[row][col] == 0) {
                    zeroCount++;
                }
            }
            
            // Update if this column has more zeros
            if (zeroCount > maxZeros) {
                maxZeros = zeroCount;
                result = col;
            }
        }
        
        return result;
    }
};
