/*
=========================================================
Problem: Middle Swap in 4x4 Matrix
Platform: GFG
Concept: 2D Array Manipulation
=========================================================

Definition:
Given a 4x4 matrix, swap:

• The 2nd row with the 3rd row
• The 2nd column with the 3rd column

Indexing is 0-based:
So:
Row 1 ↔ Row 2
Column 1 ↔ Column 2

---------------------------------------------------------

Example:

Input:
1  2  3  4
5  6  7  8
9 10 11 12
13 14 15 16

After swapping middle rows:
1  2  3  4
9 10 11 12
5  6  7  8
13 14 15 16

After swapping middle columns:
1  3  2  4
9 11 10 12
5  7  6  8
13 15 14 16

---------------------------------------------------------

IDEA:
Since matrix size is fixed (4x4),
the middle rows are:

Row 1 and Row 2

The middle columns are:

Column 1 and Column 2

We:
1. Swap elements of row 1 and row 2
2. Swap elements of column 1 and column 2

---------------------------------------------------------

APPROACH:

Step 1:
Swap entire row 1 with row 2
(Traverse columns 0 to 3)

Step 2:
Swap entire column 1 with column 2
(Traverse rows 0 to 3)

---------------------------------------------------------

Time Complexity:
O(1)  (Fixed size matrix)

Space Complexity:
O(1)

=========================================================
*/

class Solution {
  public:
    // Function to perform swap operation
    void middleSwap(int arr[4][4]) {
        
        int start = 1;
        int end = 2;
        
        while (start < end) {
            
