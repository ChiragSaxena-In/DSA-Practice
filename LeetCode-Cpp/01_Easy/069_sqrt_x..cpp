#include <climits>   // for INT_MAX

/*
    Problem: Integer Square Root
    Return floor(sqrt(x)) for a non-negative integer x
*/

/*------------------------------------------------------------
    Solution 1: Linear Scan with Overflow Protection
------------------------------------------------------------

    Intuition:
    - Start from i = 1 and keep increasing i
    - Stop when:
        1) i * i becomes greater than x
        2) OR i * i would overflow (handled using INT_MAX / i)
    - Since loop stops one step late, return i - 1

    Time Complexity: O(sqrt(x))
    Space Complexity: O(1)

    Pros:
    - Very intuitive
    - Uses only loops and conditionals
    - No division tricks or binary search

    Cons:
    - Slow for large x
*/

class SolutionLinear {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;

        int i = 1;
        while (true) {
            // Prevent overflow before squaring
            if (i > INT_MAX / i) break;

            if (i * i > x) break;

            i++;
        }

        return i - 1;   // floor(sqrt(x))
    }
};

/*------------------------------------------------------------
    Solution 2: Binary Search (Optimized)
------------------------------------------------------------

    Intuition:
    - sqrt(x) lies between 1 and x
    - Use binary search to find the largest mid such that:
            mid * mid <= x
    - To avoid overflow:
            mid * mid <= x  ==>  mid <= x / mid
    - Store valid mid in res and keep searching right side

    Time Complexity: O(log x)
    Space Complexity: O(1)

    Pros:
    - Very fast
    - Industry-standard solution
    - Safe from overflow

    Cons:
    - Slightly less intuitive than linear scan
*/

class SolutionBinary {
public:
    int mySqrt(int x) {
        
        if (x == 0) return 0;

        int start = 1, end = x;
        int mid = 0, res = 0;

        while (start <= end) {
            mid = start + (end - start) / 2;

            // mid * mid <= x  (written safely)
            if (mid <= x / mid) {
                res = mid;          // valid answer
                start = mid + 1;    // try to find larger
            } else {
                end = mid - 1;
            }
        }

        return res;
    }
};
