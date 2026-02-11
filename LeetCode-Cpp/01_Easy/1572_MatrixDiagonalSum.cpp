#include <vector>
using namespace std;

/*
===========================================================
Problem: Matrix Diagonal Sum
Platform: LeetCode 1572
Topic: 2D Arrays
===========================================================

Problem Statement:
Given a square matrix mat, return the sum of the matrix diagonals.

Only count the center element once (if n is odd).

-----------------------------------------------------------
Idea / Approach:

There are two diagonals in a square matrix:

Primary Diagonal  →  mat[i][i]
Secondary Diagonal → mat[i][n - i - 1]

For every row i:
- Add primary diagonal element.
- Add secondary diagonal element.
- But if both indices are same (center element in odd n),
  then avoid double counting.

Condition to avoid double counting:
    if (i != n - i - 1)

-----------------------------------------------------------
Time Complexity: O(n)
   → Single loop over rows

Space Complexity: O(1)
   → No extra space used

===========================================================
*/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {

        int n = mat.size();   // Since matrix is square
        int sum = 0;

        for (int i = 0; i < n; i++) {

            // Add primary diagonal element
            sum += mat[i][i];

            // Add secondary diagonal element
            // Avoid double counting the center element
            if (i != n - i - 1) {
                sum += mat[i][n - i - 1];
            }
        }

        return sum;
    }
};
