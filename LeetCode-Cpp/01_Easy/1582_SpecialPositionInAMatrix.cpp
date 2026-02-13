#include <vector>
using namespace std;

/*
=========================================================
LC 1582 - Special Positions in a Binary Matrix
=========================================================

Definition:
A position (i, j) is special if:
1. mat[i][j] == 1
2. All other elements in row i are 0
3. All other elements in column j are 0

Approach:
- For every row:
    -> Count number of 1s
    -> Store column index if found
- If row has exactly one 1:
    -> Count 1s in that column
- If column also has exactly one 1:
    -> Increment result

Time Complexity: O(m * n)
Space Complexity: O(1)
=========================================================
*/

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
        int count = 0;
        int rows = mat.size();
        int cols = mat[0].size();

        // Traverse each row
        for (int i = 0; i < rows; i++) {
            
            int colIndex = -1;
            int occurrences = 0;

            // Count 1s in current row
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 1) {
                    occurrences++;
                    colIndex = j;  // store column of 1
                }
            }

            // If row has exactly one '1'
            if (occurrences == 1) {
                
                int columnSum = 0;

                // Count 1s in that column
                for (int k = 0; k < rows; k++) {
                    columnSum += mat[k][colIndex];
                }

                // If column also has exactly one '1'
                if (columnSum == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};
