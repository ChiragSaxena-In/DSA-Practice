#include <vector>
using namespace std;
// ================================================================
// Problem: Segregate 0s and 1s
// Platform: GFG
// Approach: Two Pointer Technique
// ================================================================

/*
    Idea:
    - Use two pointers:
        start → from beginning
        end   → from end
    - Goal: move all 0s to the left and all 1s to the right.
    - If arr[start] is 0 → it's already correct, move start.
    - If arr[start] is 1:
        - Check arr[end]
        - If arr[end] is 0 → swap and move both pointers
        - Else → move end backward

    This avoids extra space and sorting.
*/

class Solution {
public:
    void segregate0and1(vector<int> &arr) {

        int start = 0;
        int end = arr.size() - 1;

        while (start <= end) {

            // Case 1: Correct position for 0
            if (arr[start] == 0) {
                start++;
            }
            else {
                // arr[start] == 1
                if (arr[end] == 0) {
                    swap(arr[start], arr[end]);
                    start++;
                    end--;
                }
                else {
                    // arr[end] == 1 → already correct
                    end--;
                }
            }
        }
    }
};

/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    Notes:
    - In-place solution
    - Order of elements does NOT matter
    - Classic two-pointer pattern
*/
