// Question -   Power of Two


/*

Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true
Explanation: 20 = 1
Example 2:

Input: 16
Output: true
Explanation: 24 = 16
Example 3:

Input: 218
Output: false
*/

// Solution

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int i = 0;
        long long val = 0;

        while(val < n) {
            val = pow(2 , i++);
            if(val == n) {
                return true;
            }
        }

        return false;
    }
};
