#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& arr, int h) {

        /*
            Problem Type:
            - Binary Search on Answer

            Goal:
            - Find the minimum eating speed such that Koko
              can finish all bananas within h hours.
        */

        int start = 1;
        int end = arr[0];
        int mid = 0;
        int ans = 0;

        // Find maximum pile (upper bound for speed)
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > end) {
                end = arr[i];
            }
        }

        // Binary Search on eating speed
        while (start <= end) {

            mid = start + (end - start) / 2;

            /*
                Calculate total hours needed
                if eating speed is 'mid'
            */
            long long time = 0;

            for (int i = 0; i < arr.size(); i++) {
                time += arr[i] / mid;
                if (arr[i] % mid != 0) {
                    time++;
                }
            }

            // If speed is too slow
            if (time > h) {
                start = mid + 1;
            }
            // If speed is feasible, try minimizing it
            else {
                ans = mid;
                end = mid - 1;
            }
        }

        return ans;
    }
};
