# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if not root:
            return

        self.preOrder: list[TreeNode] = []

        def findPreorder(root: TreeNode | None) -> TreeNode | None:

            if not root:
                return None

            self.preOrder.append(root)
            findPreorder(root.left)
            findPreorder(root.right)

        findPreorder(root)

        curr_node: TreeNode = root
        for i in range(1, len(self.preOrder)):
            curr_node.left = None
            curr_node.right = self.preOrder[i]

            curr_node = curr_node.right