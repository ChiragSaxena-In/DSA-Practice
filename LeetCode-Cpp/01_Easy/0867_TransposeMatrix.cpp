#include <vector>
using namespace std;

/*
===========================================================
Problem: Transpose Matrix
Platform: LeetCode 867
Topic: 2D Arrays
===========================================================

Problem Statement:
Given a 2D matrix of size m x n, return its transpose.

The transpose of a matrix is formed by converting rows into columns.
Element at position (i, j) becomes (j, i).

-----------------------------------------------------------
Idea / Approach:

If original matrix is:
m rows and n columns

Transpose will be:
n rows and m columns

So:
1. Create a result matrix of size n x m.
2. Traverse original matrix.
3. For every element (i, j), place it at (j, i) in result.

Key Mapping:
result[j][i] = matrix[i][j]

-----------------------------------------------------------
Time Complexity: O(m * n)
    We visit every element once.

Space Complexity: O(m * n)
    We create a new matrix to store transpose.

===========================================================
*/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        // Transposed matrix will have n rows and m columns
        vector<vector<int>> sol(n, vector<int>(m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Swap row and column indices
                sol[j][i] = matrix[i][j];
            }
        }

        return sol;
    }
};
