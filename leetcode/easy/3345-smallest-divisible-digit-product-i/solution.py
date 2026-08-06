class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        if n == 100 or n % 10 == 0:
            return n

        # for 1 digits number
        if n <= 9:
            for i in range(n, 10):
                if i % t == 0:
                    return i
            return 10

        # for 2 digits
        for i in range(n, (n+10) - (n % 10)):
            if ((i % 10) * ((i // 10) % 10)) % t == 0:
                return i
        
        return (n + 10) - (n % 10)