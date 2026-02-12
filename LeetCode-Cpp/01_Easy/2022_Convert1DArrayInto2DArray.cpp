#include <vector>
using namespace std;

/*
============================================================
Problem: Convert 1D Array Into 2D Array
Platform: LeetCode (LC 2022)
Concept: 2D Arrays, Index Mapping, Row-Major Order
============================================================

Definition:
Given a 0-indexed 1D array "original" and two integers m and n,
construct a 2D array with:

1) m rows
2) n columns

The matrix must be filled in row-major order.

If it is impossible to reshape (i.e., total elements do not match),
return an empty 2D array.

------------------------------------------------------------
Example:

Input:
original = [1, 2, 3, 4]
m = 2
n = 2

Output:
[
 [1, 2],
 [3, 4]
]

Explanation:
Elements are filled row by row.
------------------------------------------------------------

IDEA:
To form an m x n matrix:
    Total elements required = m * n

If:
    original.size() != m * n
Then:
    Reshaping is impossible.

Otherwise:
    Convert 1D index into 2D position using:

        row = i / n
        col = i % n

This correctly maps elements in row-major order.

------------------------------------------------------------
APPROACH:
- First, check if reshaping is valid.
- If not valid, return empty matrix.
- Create an m x n matrix.
- Traverse original array once.
- Place each element using:
        matrix[i/n][i%n]

------------------------------------------------------------
Time Complexity:
O(k)
Where k = original.size()

We traverse the array once.

Space Complexity:
O(m * n)
For storing the resulting 2D matrix.
============================================================
*/

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
        // Check if reshape is possible
        if (original.size() != m * n)
            return {};
        
        // Create m x n matrix
        vector<vector<int>> matrix(m, vector<int>(n));
        
        // Fill matrix in row-major order
        for (int i = 0; i < original.size(); i++) {
            matrix[i / n][i % n] = original[i];
        }
        
        return matrix;
    }
};
