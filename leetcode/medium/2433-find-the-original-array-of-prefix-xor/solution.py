class Solution:
    def findArray(self, pref: List[int]) -> List[int]:
        n = len(pref)

        ans: list[int] = [0] * n
        ans[0] = pref[0]

        for i in range(1, n):
            ans[i] = pref[i - 1] ^ pref[i]

        return ans