class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        prev_max = nums[0]
        prev_min = nums[0]
        result = nums[0]

        for i in range(1, len(nums)):
            curr = max(nums[i], prev_max * nums[i], prev_min * nums[i])
            prev_min = min(nums[i], prev_max * nums[i], prev_min * nums[i])
            prev_max = curr

            result = max(result, prev_max)

        return result
