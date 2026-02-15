#include <vector>
using namespace std;

/*
=========================================================
Problem: Sum of Row and Column
Platform: GFG
Concept: 2D Array Traversal
=========================================================

Definition:
Given a matrix of size N x M, check whether for every index i
(0 ≤ i < min(N, M)), the sum of i-th row is equal to the sum of
i-th column.

Return:
1 → If all corresponding row and column sums are equal
0 → Otherwise

Example:

Input:
N = 3, M = 3
1 2 3
4 5 6
7 8 9

Row 0 sum = 1+2+3 = 6
Col 0 sum = 1+4+7 = 12  → Not equal

Output: 0
---------------------------------------------------------

IDEA:
For each index i:
• Compute sum of row i
• Compute sum of column i
• Compare both

If any mismatch → return 0 immediately.
If all match → return 1.

---------------------------------------------------------

APPROACH:
1. Iterate i from 0 to min(N, M)-1
2. For each i:
   - Traverse full row → j < M
   - Traverse full column → j < N
3. Compare sums
4. Return result

---------------------------------------------------------

Time Complexity:
O(N × M)

Space Complexity:
O(1)

=========================================================
*/

class Solution {
  public:
    int sumOfRowCol(int N, int M, vector<vector<int>> A) {
        
        // Traverse till minimum dimension
        for (int i = 0; i < min(N, M); i++) {
            
            int sum_row = 0;
            int sum_col = 0;
            
            // Calculate sum of i-th row
            for (int j = 0; j < M; j++) {
                sum_row += A[i][j];
            }
            
            // Calculate sum of i-th column
            for (int j = 0; j < N; j++) {
                sum_col += A[j][i];
            }
            
            // If mismatch found, return 0 immediately
            if (sum_row != sum_col)
                return 0;
        }
        
        // If all matched
        return 1;
    }
};
