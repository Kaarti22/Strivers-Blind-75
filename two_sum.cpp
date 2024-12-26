/*
Link: https://leetcode.com/problems/two-sum/description/

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>v = nums;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j = n-1;
        int a = -1, b = -1;
        while(i < j){
            int sum = nums[i] + nums[j];
            if(sum == target){
                a = nums[i];
                b = nums[j];
                break;
            }
            if(sum < target) i++;
            else j--;
        }
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(v[i] == a){
                ans.push_back(i);
                break;
            }
        }
        for(int i=0; i<n; i++){
            if(v[i] == b && ans.back() != i){
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};