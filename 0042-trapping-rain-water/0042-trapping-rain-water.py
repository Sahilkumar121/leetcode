class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        right_max_bilding = [0] * n
        left_max_building = [0] * n

        # max left building
        left_max_building[0] = height[0]
        for i in range(1, n):
            left_max_building[i] = max(left_max_building[i - 1], height[i])

        # for right building
        right_max_bilding[n - 1] = height[n - 1]
        for i in range(n - 2, -1, -1):
            right_max_bilding[i] = max(right_max_bilding[i + 1], height[i])
        
        total_water = 0

        for i in range(n):
            total_water += min(left_max_building[i], right_max_bilding[i]) - height[i]

        return total_water