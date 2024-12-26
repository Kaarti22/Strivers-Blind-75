/*
Link: https://leetcode.com/problems/maximum-product-subarray/description/

Given an integer array nums, find a 
subarray
 that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

Constraints:

1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any subarray of nums is guaranteed to fit in a 32-bit integer.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = *max_element(nums.begin(), nums.end());
        int currMin = 1, currMax = 1;
        for(auto it: nums){
            if(it == 0){
                currMin = 1, currMax = 1;
            } else {
                int temp = currMax * it;
                currMax = max({temp, currMin * it, it});
                currMin = min({temp, currMin * it, it});
                ans = max(ans, currMax);
            }
        }
        return ans;
    }
};