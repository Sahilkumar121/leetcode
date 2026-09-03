# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.inorder: list[int] = []

        def findInorder(root: TreeNode | None) -> None:

            if not root:
                return

            findInorder(root.left)
            self.inorder.append(root.val)
            findInorder(root.right)

        findInorder(root)
        
        return self.inorder[k - 1]