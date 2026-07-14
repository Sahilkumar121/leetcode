//
// Created by sleep on 2026-07-14.
//


#include <vector>
#include <iostream>

using namespace std;


/*
Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

max_sum = -1
curr_sum = 0

-2 1 -3 4 -1 2 1 -5 4

*/

class Solution {
public:
    static int maxSubArray(const vector<int>& nums) {
        int max_sum = nums[0];
        int max_ending = nums[0];

        for (int i=0; i<static_cast<int>(nums.size()); i++) {
            max_ending = max(nums[i], max_ending + nums[i]);

            max_sum = max(max_sum, max_ending);
        }

        return max_sum;
    }
};

int main() {
    cout << Solution::maxSubArray({-2,1,-3,4,-1,2,1,-5,4}) << "\n";
}
