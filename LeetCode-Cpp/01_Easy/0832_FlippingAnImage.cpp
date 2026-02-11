#include <vector>
using namespace std;

/*
===========================================
Problem: Flip and Invert Image
Platform: LeetCode
Concepts Used: 2D Arrays, Two Pointers
===========================================
*/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {

        int rows = image.size();
        int cols = image[0].size();

        for (int i = 0; i < rows; i++) {

            int start = 0;
            int end = cols - 1;

            // Process one row at a time
            while (start <= end) {

                // If both pointers meet (middle element in odd length row)
                if (start == end) {
                    image[i][start] = !image[i][start];  // Just invert once
                } 
                else {
                    // Invert both elements first
                    image[i][start] = !image[i][start];
                    image[i][end]   = !image[i][end];

                    // Then swap to achieve horizontal flip
                    swap(image[i][start], image[i][end]);
                }

                start++;
                end--;
            }
        }

        return image;  // In-place modification
    }
};
