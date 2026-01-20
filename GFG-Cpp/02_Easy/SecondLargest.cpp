#include <vector>
#include <climits>
using namespace std;

// Problem: Find Second Largest Element in an Array
// Approach: Single Traversal
// Idea:
// - Maintain largest and second largest DISTINCT elements
// - Update them carefully during one pass

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {

        int largest = INT_MIN;
        int secondLargest = INT_MIN;

        for (int i = 0; i < arr.size(); i++) {

            // Case 1: New largest found
            if (arr[i] > largest) {
                secondLargest = largest;
                largest = arr[i];
            }
            // Case 2: Valid candidate for second largest (distinct)
            else if (arr[i] < largest && arr[i] > secondLargest) {
                secondLargest = arr[i];
            }
        }

        // If second largest was never updated, it doesn't exist
        if (secondLargest == INT_MIN)
            return -1;

        return secondLargest;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)

Key Guarantees:
- Handles negative values
- Ignores duplicates
- No sorting
- No extra space
*/
