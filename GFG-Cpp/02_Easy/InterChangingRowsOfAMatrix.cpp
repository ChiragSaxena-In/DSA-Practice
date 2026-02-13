#include <vector>
using namespace std;

/*
=========================================================
Interchange Rows of a Matrix
=========================================================

Definition:
Reverse the rows of a matrix in-place.
Swap first row with last row,
second row with second last row, and so on.

Approach:
- Use two pointers: start and end.
- While start < end:
    -> Swap corresponding elements of both rows.
- Move pointers inward.

Time Complexity: O(N * M)
Space Complexity: O(1)
=========================================================
*/

class Solution {
public:
    void interchangeRows(vector<vector<int> > &mat) {
        
        int rows = mat.size();
        int cols = mat[0].size();
        
        int start = 0;
        int end = rows - 1;
        
        // Reverse rows using two-pointer technique
        while (start < end) {
            
            for (int col = 0; col < cols; col++) {
                swap(mat[start][col], mat[end][col]);
            }
            
            start++;
            end--;
        }
    }
};
