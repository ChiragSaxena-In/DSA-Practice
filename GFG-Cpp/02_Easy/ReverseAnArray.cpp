#include <vector>
using namespace std;

// ============================================================
// Problem: Reverse an Array
// Approach: Two Pointer Technique
// ============================================================

/*
    Idea:
    - Use two pointers:
        start → beginning of array
        end   → end of array
    - Swap elements at start and end
    - Move start forward and end backward
    - Continue until both pointers cross

    Why it works:
    - Each swap places two elements in their correct reversed position
    - No extra space is used (in-place reversal)
*/

class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        int start = 0;
        int end = arr.size() - 1;

        // Continue until pointers cross
        while (start <= end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
};

/*
    Time Complexity:  O(n)
    Space Complexity: O(1)

    Notes:
    - Using `start <= end` is safe.
    - When start == end (odd-sized array), swapping the middle element
      with itself causes no issue.
*/
