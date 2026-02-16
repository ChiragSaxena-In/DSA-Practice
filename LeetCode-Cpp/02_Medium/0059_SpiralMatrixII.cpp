#include <vector>
using namespace std;

/*
=========================================================
 LC 59 - Spiral Matrix II
=========================================================

Given an integer n, generate an n x n matrix filled
with numbers from 1 to n^2 in spiral order.

Approach:
- Maintain 4 boundaries: top, bottom, left, right
- Fill in 4 directions
- Shrink boundaries after each traversal
- Continue until num > n*n

Time Complexity  : O(n^2)
Space Complexity : O(n^2)
=========================================================
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> mat(n, vector<int>(n));

        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;

        int num = 1;

        while (num <= n * n && top <= bottom && left <= right) {

            // 1️⃣ Top Row (Left → Right)
            for (int j = left; j <= right; j++) {
                mat[top][j] = num++;
            }
            top++;

            // 2️⃣ Right Column (Top → Bottom)
            for (int j = top; j <= bottom; j++) {
                mat[j][right] = num++;
            }
            right--;

            // 3️⃣ Bottom Row (Right → Left)
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    mat[bottom][j] = num++;
                }
                bottom--;
            }

            // 4️⃣ Left Column (Bottom → Top)
            if (left <= right) {
                for (int j = bottom; j >= top; j--) {
                    mat[j][left] = num++;
                }
                left++;
            }
        }

        return mat;
    }
};
