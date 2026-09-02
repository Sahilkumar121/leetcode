# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def lowestCommonAncestor(
        self, root: "TreeNode", p: "TreeNode", q: "TreeNode"
    ) -> "TreeNode":

        if not root:
            return None

        if root == p:
            return p

        if root == q:
            return q

        left_n = self.lowestCommonAncestor(root.left, p, q)
        right_n = self.lowestCommonAncestor(root.right, p, q)

        if left_n is not None and right_n is not None:
            return root
        elif left_n is not None and right_n is None:
            return left_n
        else:
            return right_n
