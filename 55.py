from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        target = len(nums) - 1
        max_reachable = 0

        for i, num in enumerate(nums):
            if i > max_reachable:
                return False

            max_reachable = max(max_reachable, i + num)

            if max_reachable >= target:
                return True

        return max_reachable >= target
