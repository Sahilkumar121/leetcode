from typing import List


class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:

        n = len(nums)
        left_pointer = 0

        total_sum = 0
        min_length = n + 1

        for right_pointer in range(len(nums)):
            total_sum += nums[right_pointer]

            while total_sum >= target:
                min_length = min(min_length, right_pointer - left_pointer + 1)

                total_sum -= nums[left_pointer]
                left_pointer += 1

        return min_length if min_length != n + 1 else 0


sol = Solution()
print(sol.minSubArrayLen(target=11, nums=[1, 1, 1, 1, 1, 1, 1, 1]))
