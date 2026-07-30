class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        gola_pointer = -1

        for i in range(n - 1, 0, -1):
            if nums[i] > nums[i - 1]:
                gola_pointer = i - 1
                break
        
        if gola_pointer != -1:
            for i in range(n - 1, gola_pointer, -1):
                if nums[i] > nums[gola_pointer]:
                    nums[gola_pointer], nums[i] = nums[i], nums[gola_pointer]
                    break

        nums[gola_pointer + 1 :] = reversed(nums[gola_pointer + 1 :])