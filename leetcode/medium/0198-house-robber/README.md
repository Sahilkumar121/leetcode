# House Robber

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and  **it will automatically contact the police if two adjacent houses were broken into on the same night**.

Given an integer array `nums` representing the amount of money of each house, return  *the maximum amount of money you can rob tonight  **without alerting the police***.

 

 **Example 1:** 

```
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

```

 **Example 2:** 

```
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

```

 

 **Constraints:** 

- 1 <= nums.length <= 100
- 0 <= nums[i] <= 400

## Solution

**Language:** C++  
**Runtime:** 3 ms (beats 6.18%)  
**Memory:** 10.6 MB (beats 47.07%)  
**Submitted:** 2026-08-28T05:40:13.227Z  

```cpp

class Solution
{
    vector<int> memo;

public:
    int solve(vector<int> &nums, int i, int n)
    {
        if (i >= n)
        {
            return 0;
        }

        if (memo[i] != -1)
        {
            return memo[i];
        }

        int steal = nums[i] + solve(nums, i + 2, n);
        int skip = solve(nums, i + 1, n);

        return memo[i] = max(steal, skip);
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();

        memo.assign(n + 1, -1);

        return solve(nums, 0, n);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/house-robber/)