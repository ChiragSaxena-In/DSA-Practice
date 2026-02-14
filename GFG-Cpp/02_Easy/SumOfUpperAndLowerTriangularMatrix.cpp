#include <vector>
using namespace std;

/*
=========================================================
Sum of Upper and Lower Triangles of a Matrix
=========================================================

Definition:
Return a vector containing:
[ sum of upper triangle, sum of lower triangle ]

Upper Triangle Condition: j >= i
Lower Triangle Condition: i >= j

Optimized Traversal:
For each i:
    for j = i to N-1:
        usum += mat[i][j]
        lsum += mat[j][i]

Time Complexity: O(N^2)
Space Complexity: O(1)
=========================================================
*/

class Solution {
public:
    vector<int> sumTriangles(vector<vector<int>>& mat) {
        
        int n = mat.size();
        
        int upperSum = 0;
        int lowerSum = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                
                upperSum += mat[i][j];
                lowerSum += mat[j][i];
            }
        }
        
        return {upperSum, lowerSum};
    }
};
