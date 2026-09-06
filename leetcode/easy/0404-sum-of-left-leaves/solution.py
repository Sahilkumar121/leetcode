# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        if root and not root.left and not root.right:
            return 0

        self.sum = 0

        def solve(root: TreeNode | None, side: int):

            if not root:
                return

            if not root.left and not root.right and side == 1:
                self.sum += root.val
                return

            if root.left:
                solve(root.left, 1)
            if root.right:
                solve(root.right, 0)

        solve(root, -1)
        return self.sum