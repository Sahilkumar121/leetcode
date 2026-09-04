# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        self.goodNode = 0

        def checkGoodNode(root: TreeNode | None, max_num: int) -> None:
            if not root:
                return

            if root.val >= max_num:
                self.goodNode += 1

            checkGoodNode(root.left, max(root.val, max_num))
            checkGoodNode(root.right, max(root.val, max_num))

        checkGoodNode(root, -(10**4) - 1)
        return self.goodNode