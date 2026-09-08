class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        sum_number = sum(nums)

        return sum_number % k