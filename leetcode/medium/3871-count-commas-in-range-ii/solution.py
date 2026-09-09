class Solution:
    def countCommas(self, n: int) -> int:
        lower = 1000
        comma = 1
        result = 0

        while lower <= n:
            upper = lower * 1000 - 1
            upper = min(upper, n)

            count_number = (upper - lower) + 1
            result += count_number * comma

            lower *= 1000
            comma += 1

        return result