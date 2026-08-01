class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            return self.findMedianSortedArrays(nums2, nums1)

        m = len(nums1)
        n = len(nums2)

        l = 0
        r = m

        while l <= r:
            Px = l + (r - l) // 2
            Py = (m + n + 1) // 2 - Px

            # left part
            x1 = -sys.maxsize if Px == 0 else nums1[Px - 1]
            x2 = -sys.maxsize if Py == 0 else nums2[Py - 1]

            # right part
            x3 = sys.maxsize if Px == m else nums1[Px]
            x4 = sys.maxsize if Py == n else nums2[Py]

            if x1 <= x4 and x2 <= x3:
                if (m + n) % 2 != 0:
                    return max(x1, x2)
                else:
                    return (max(x1, x2) + min(x3, x4)) / 2

            if x1 > x4:
                r = Px - 1

            else:
                l = Px + 1

        return -1