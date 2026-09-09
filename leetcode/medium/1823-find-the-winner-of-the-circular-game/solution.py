class Solution:
    def findTheWinner(self, n: int, k: int) -> int:

        def findWinnerIdx(n: int, k: int) -> int:
            if n == 1:
                return 0

            idx = findWinnerIdx(n - 1, k)
            idx = (idx + k) % n

            return idx

        return findWinnerIdx(n, k) + 1
