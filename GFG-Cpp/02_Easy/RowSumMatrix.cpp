#include <vector>
using namespace std;

/*
=========================================================
Row Sum of a Matrix
=========================================================

Definition:
Return a vector where each element represents
the sum of elements of that row in the matrix.

Approach:
- Create a result vector of size = number of rows.
- Traverse matrix row-wise.
- Add each element to its corresponding row sum.

Time Complexity: O(m * n)
Space Complexity: O(m)
=========================================================
*/

class Solution {
public:
    vector<int> rowSum(vector<vector<int>>& mat) {
        
        int rows = mat.size();
        int cols = mat[0].size();
        
        vector<int> res(rows, 0);
        
        // Traverse each row
        for (int i = 0; i < rows; i++) {
            
            // Traverse columns of that row
            for (int j = 0; j < cols; j++) {
                res[i] += mat[i][j];
            }
        }
        
        return res;
    }
};
