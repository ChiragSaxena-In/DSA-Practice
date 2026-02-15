#include <vector>
using namespace std;

/*
=========================================================
Problem: Matrix Addition
Platform: GFG
Concept: 2D Array Traversal
=========================================================

Definition:
Given two matrices of the same dimensions,
add matrixB into matrixA element-wise.

The result must be stored in matrixA itself.

---------------------------------------------------------

Example:

Input:
Matrix A:
1 2 3
4 5 6

Matrix B:
7 8 9
1 2 3

Output (stored in A):
8 10 12
5  7  9

---------------------------------------------------------

IDEA:
Matrix addition is performed element-wise.

For every position (i, j):
A[i][j] = A[i][j] + B[i][j]

Since both matrices have same dimensions,
we can traverse normally using nested loops.

---------------------------------------------------------

APPROACH:

1. Traverse all rows
2. Traverse all columns
3. Add corresponding element from matrixB
4. Store result back into matrixA

---------------------------------------------------------

Time Complexity:
O(N × M)

Space Complexity:
O(1)  (In-place modification)

=========================================================
*/

class Solution {
  public:
    void Addition(vector<vector<int>>& matrixA, vector<vector<int>>& matrixB) {
        
        int N = matrixA.size();
        int M = matrixA[0].size();
        
        // Traverse matrix
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                matrixA[i][j] += matrixB[i][j];
            }
        }
    }
};
