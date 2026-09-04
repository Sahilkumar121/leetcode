# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        self.max = 2**31
        self.min = -(2**31) - 1

        def solve(root: TreeNode | None, max: int, min: int):
            if not root:
                return True

            if root.val >= max or root.val <= min:
                return False

            return solve(root.left, root.val, min) and solve(root.right, max, root.val)

        return solve(root, self.max, self.min)