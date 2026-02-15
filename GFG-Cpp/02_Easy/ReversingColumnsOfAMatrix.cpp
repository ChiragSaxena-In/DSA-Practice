#include <vector>
using namespace std;

/*
=========================================================
Problem: Reverse Columns of a Matrix
Platform: GFG
Concept: 2D Array Traversal + Two Pointer Technique
=========================================================

Definition:
Given a matrix, reverse each row's column order.
That means:
• First column swaps with last column
• Second column swaps with second last column
and so on.

The reversal must be done in-place.

---------------------------------------------------------

Example:

Input:
1 2 3
4 5 6
7 8 9

Output:
3 2 1
6 5 4
9 8 7

---------------------------------------------------------

IDEA:
To reverse columns:
We use two pointers:
• start → leftmost column
• end → rightmost column

For each pair:
Swap elements vertically across all rows.

---------------------------------------------------------

APPROACH:

1. Initialize:
   start = 0
   end = number_of_columns - 1

2. While start < end:
   • For each row:
       swap(matrix[row][start], matrix[row][end])
   • Move start forward
   • Move end backward

---------------------------------------------------------

Time Complexity:
O(N × M)

Space Complexity:
O(1)  (In-place modification)

=========================================================
*/

class Solution {
  public:

    void reverseCol(vector<vector<int> > &matrix) {
        
        int N = matrix.size();
        int M = matrix[0].size();
        
        int start = 0;
        int end = M - 1;
        
        // Reverse columns using two-pointer technique
        while (start < end) {
            
            for (int i = 0; i < N; i++) {
                swap(matrix[i][start], matrix[i][end]);
            }
            
            start++;
            end--;
        }
    }
};
