#include <vector>
using namespace std;

/*
=========================================================
Problem: Snake Pattern Traversal
Platform: GFG
Concept: 2D Array Traversal
=========================================================

Definition:
Given a matrix of size N x M,
return elements in snake pattern.

Snake pattern means:
• Traverse first row → left to right
• Traverse second row → right to left
• Traverse third row → left to right
and so on...

---------------------------------------------------------

Example:

Input:
1 2 3
4 5 6
7 8 9

Output:
1 2 3 6 5 4 7 8 9

---------------------------------------------------------

IDEA:
For each row:
• If row index is even → traverse left to right
• If row index is odd → traverse right to left

Alternate direction on every row.

---------------------------------------------------------

APPROACH:

1. Let N = number of rows
2. Let M = number of columns
3. Traverse each row:
   - If i % 2 == 0:
       j = 0 → M-1
   - Else:
       j = M-1 → 0
4. Push elements into result vector

---------------------------------------------------------

Time Complexity:
O(N × M)

Space Complexity:
O(N × M)  (for result vector)

=========================================================
*/

class Solution {
  public:
    vector<int> snakePattern(vector<vector<int> > matrix) {
        
        int N = matrix.size();
        int M = matrix[0].size();
        
        vector<int> res;
        res.reserve(N * M);  // Avoid repeated reallocations
        
        for (int i = 0; i < N; i++) {
            
            if (i % 2 == 0) {
                // Left to right
                for (int j = 0; j < M; j++) {
                    res.push_back(matrix[i][j]);
                }
            } 
            else {
                // Right to left
                for (int j = M - 1; j >= 0; j--) {
                    res.push_back(matrix[i][j]);
                }
            }
        }
        
        return res;
    }
};
