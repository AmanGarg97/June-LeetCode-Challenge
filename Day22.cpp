// Question -   Single Number II

/*
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
*/

// Solution
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int ans =0, temp=0;
        for(int i=0; i<32; i++)
        {
            temp = 0;
            for(int j=0; j<nums.size(); j++)
            {
                temp += (nums[j]>>i)&1;
            }
            temp = temp%3;
            ans |= temp<<i;
        }
        return ans;
    }
};
