#include <vector>
#include <climits>
using namespace std;

/*
============================================================
Problem: Lucky Numbers in a Matrix
Platform: LeetCode
Concept: 2D Arrays, Row & Column Traversal
============================================================

Definition:
A Lucky Number is an element that is:
1) Minimum in its row
2) Maximum in its column

------------------------------------------------------------
Example:
Input:
[
 [3, 7, 8],
 [9, 11, 13],
 [15, 16, 17]
]

Output:
[15]

Because:
15 is the smallest in its row
15 is the largest in its column
------------------------------------------------------------

IDEA:
For each row:
    Step 1 -> Find the minimum element in that row.
    Step 2 -> Check if that element is also the maximum in its column.
    Step 3 -> If yes, add it to result.

------------------------------------------------------------
APPROACH:
- Traverse each row
- Track smallest element and its column index
- Traverse that column
- If any element in that column is greater -> not lucky
- Otherwise push to result

------------------------------------------------------------
Time Complexity:
O(n * (m + n))
For each row -> scan row + scan column

Space Complexity:
O(1) (excluding output vector)
============================================================
*/

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        
        vector<int> result;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // Traverse each row
        for (int i = 0; i < rows; i++) {
            
            int smallestInRow = INT_MAX;
            int searchCol = 0;
            
            // Step 1: Find minimum in current row
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] < smallestInRow) {
                    smallestInRow = matrix[i][j];
                    searchCol = j;   // Store column index
                }
            }
            
            // Step 2: Check if it is maximum in that column
            bool isLucky = true;
            
            for (int k = 0; k < rows; k++) {
                
                // If any element in column is greater,
                // then smallestInRow is NOT column maximum
                if (matrix[k][searchCol] > smallestInRow) {
                    isLucky = false;
                    break;   // Early exit
                }
            }
            
            // Step 3: If both conditions satisfied
            if (isLucky) {
                result.push_back(smallestInRow);
            }
        }
        
        return result;
    }
};
