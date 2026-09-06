# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        self.mode = []
        self.currVal = 0
        self.currFreq = 0
        self.maxFreq = 0

        def in_order(node: TreeNode | None):
            if not node:
                return

            in_order(node.left)

            if node.val == self.currVal:
                self.currFreq += 1
            else:
                self.currVal = node.val
                self.currFreq = 1

            if self.currFreq > self.maxFreq:
                self.maxFreq = self.currFreq
                self.mode = [self.currVal]
            elif self.currFreq == self.maxFreq:
                self.mode.append(self.currVal)

            in_order(node.right)

        in_order(root)
        return self.mode