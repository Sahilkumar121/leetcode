# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        inorder_map = {val: index for index, val in enumerate(inorder)}

        self.preorder_idx = 0

        def solve(start, end) -> TreeNode | None:

            if start > end:
                return None

            root_val = preorder[self.preorder_idx]
            self.preorder_idx += 1
            root = TreeNode(root_val)

            p = inorder_map[root_val]

            root.left = solve(start, p - 1)
            root.right = solve(p + 1, end)

            return root

        return solve(0, len(inorder) - 1)