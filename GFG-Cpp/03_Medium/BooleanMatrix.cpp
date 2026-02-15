#include <vector>
using namespace std;

/*
=========================================================
Problem: Boolean Matrix
Platform: GFG
Concept: 2D Array Traversal + Marking Technique
=========================================================

Definition:
Given a matrix, if any cell mat[i][j] is 1,
then set all elements of row i and column j to 1.

The modification must be done in-place.

---------------------------------------------------------

Example:

Input:
1 0 0
0 0 0
0 0 1

Output:
1 1 1
1 0 1
1 1 1

---------------------------------------------------------

IDEA:
If a cell contains 1,
its entire row and column must become 1.

Instead of immediately modifying the matrix
(which would affect future checks),

We:
1. First mark which rows and columns need to be updated.
2. Then update the matrix in a second traversal.

---------------------------------------------------------

APPROACH:

Step 1:
Create two arrays:
• row[N] → marks rows to be converted to 1
• col[M] → marks columns to be converted to 1

Step 2:
Traverse matrix:
If mat[i][j] == 1:
    row[i] = 1
    col[j] = 1

Step 3:
Traverse again:
If row[i] == 1 OR col[j] == 1:
    mat[i][j] = 1

---------------------------------------------------------

Time Complexity:
O(N × M)

Space Complexity:
O(N + M)

=========================================================
*/

class Solution {
  public:
    void booleanMatrix(vector<vector<int>>& mat) {
        
        int N = mat.size();
        int M = mat[0].size();
        
        // Marking arrays
        vector<int> row(N, 0);
        vector<int> col(M, 0);
        
        // First pass: mark rows and columns
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (mat[i][j] == 1) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        
        // Second pass: update matrix
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (row[i] == 1 || col[j] == 1) {
                    mat[i][j] = 1;
                }
            }
        }
    }
};
