# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        if not root:
            return []

        self.path_list: list[str] = []

        def solve(root: TreeNode, currentPath: str):
            if not root.left and not root.right:
                currentPath += str(root.val)
                self.path_list.append(currentPath)
                return

            currentPath += str(root.val) + "->"

            if root.left:
                solve(root.left, currentPath)

            if root.right:
                solve(root.right, currentPath)

        solve(root, "")
        return self.path_list