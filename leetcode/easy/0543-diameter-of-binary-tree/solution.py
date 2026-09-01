# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    __maxDiameter = 0

    def get_depth(self, root: TreeNode) -> int:
        if root is None:
            return 0

        left_part = self.get_depth(root.left)
        right_part = self.get_depth(root.right)

        self.__maxDiameter = max(self.__maxDiameter, left_part + right_part)

        return max(left_part, right_part) + 1

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.__maxDiameter = 0

        self.get_depth(root)
        return self.__maxDiameter
