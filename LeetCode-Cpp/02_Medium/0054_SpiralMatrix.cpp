#include <vector>
using namespace std;

/*
=========================================================
 LC 54 - Spiral Matrix
=========================================================

Given an m x n matrix, return all elements in spiral order.

Approach:
- Maintain 4 boundaries: top, bottom, left, right
- Traverse in 4 directions
- Shrink boundaries after each traversal
- Stop when boundaries cross

Time Complexity  : O(m * n)
Space Complexity : O(1) (excluding result vector)
=========================================================
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {

        vector<int> res;

        int top = 0;
        int bottom = mat.size() - 1;
        int left = 0;
        int right = mat[0].size() - 1;

        while (top <= bottom && left <= right) {

            // 1️⃣ Traverse Top Row (Left → Right)
            for (int i = left; i <= right; i++) {
                res.push_back(mat[top][i]);
            }
            top++;

            // 2️⃣ Traverse Right Column (Top → Bottom)
            for (int i = top; i <= bottom; i++) {
                res.push_back(mat[i][right]);
            }
            right--;

            // 3️⃣ Traverse Bottom Row (Right → Left)
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    res.push_back(mat[bottom][i]);
                }
                bottom--;
            }

            // 4️⃣ Traverse Left Column (Bottom → Top)
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    res.push_back(mat[i][left]);
                }
                left++;
            }
        }

        return res;
    }
};
