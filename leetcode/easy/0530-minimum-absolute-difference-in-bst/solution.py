# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        self.inorder_list = []

        def inorder(root: TreeNode | None):
            if not root:
                return

            inorder(root.left)
            self.inorder_list.append(root.val)
            inorder(root.right)

        inorder(root)

        self.min_diff = 10**5 + 1
        for i in range(1, len(self.inorder_list)):
            diff = abs(self.inorder_list[i] - self.inorder_list[i - 1])
            self.min_diff = min(self.min_diff, diff)

        return self.min_diff