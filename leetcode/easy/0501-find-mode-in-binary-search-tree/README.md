# Find Mode in Binary Search Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given the `root` of a binary search tree (BST) with duplicates, return  *all the mode(s) (i.e., the most frequently occurred element) in it*.

If the tree has more than one mode, return them in  **any order**.

Assume a BST is defined as follows:

- The left subtree of a node contains only nodes with keys less than or equal to the node's key.
- The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
- Both the left and right subtrees must also be binary search trees.

 

 **Example 1:** 

```
Input: root = [1,null,2,2]
Output: [2]

```

 **Example 2:** 

```
Input: root = [0]
Output: [0]

```

 

 **Constraints:** 

- The number of nodes in the tree is in the range [1, 104].
- -105 <= Node.val <= 105

 

 **Follow up:**  Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).

## Solution

**Language:** Python  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 22 MB (beats 82.88%)  
**Submitted:** 2026-09-06T16:21:14.039Z  

```py
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
```

---

[View on LeetCode](https://leetcode.com/problems/find-mode-in-binary-search-tree/)