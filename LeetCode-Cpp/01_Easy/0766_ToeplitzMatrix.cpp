#include <vector>
using namespace std;

/*
=========================================================
LC 766 - Toeplitz Matrix
=========================================================

Definition:
A matrix is Toeplitz if every diagonal from
top-left to bottom-right contains the same element.

Condition:
matrix[i][j] == matrix[i-1][j-1]

Approach:
- Start traversal from (1,1).
- Compare each element with its top-left neighbor.
- If any mismatch occurs, return false.
- If all checks pass, return true.

Time Complexity: O(m * n)
Space Complexity: O(1)
=========================================================
*/

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                
                if (matrix[i][j] != matrix[i - 1][j - 1]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
