# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root:
            return False

        def solve(root: TreeNode | None, sum: int, target: int) -> bool:
            if not root:
                return False

            if not root.left and not root.right and root.val + sum == target:
                return True

            return solve(root.left, root.val + sum, target) or solve(
                root.right, root.val + sum, target
            )

        return solve(root, 0, targetSum)