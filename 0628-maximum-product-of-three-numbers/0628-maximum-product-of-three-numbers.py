class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        max1_num = max2_num = max3_num = -sys.maxsize

        min1_num = min2_num = sys.maxsize

        for num in nums:
            if num > max1_num:
                max3_num = max2_num
                max2_num = max1_num
                max1_num = num
            elif num > max2_num:
                max3_num = max2_num
                max2_num = num
            elif num > max3_num:
                max3_num = num

            if num < min1_num:
                min2_num = min1_num
                min1_num = num
            elif num < min2_num:
                min2_num = num

        return max(
            max1_num * max2_num * max3_num,
            min1_num * min2_num * max1_num,
        )