# Diameter of Binary Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given the `root` of a binary tree, return  *the length of the  **diameter**  of the tree*.

The  **diameter**  of a binary tree is the  **length**  of the longest path between any two nodes in a tree. This path may or may not pass through the `root`.

The  **length**  of a path between two nodes is represented by the number of edges between them.

 

 **Example 1:** 

```
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

```

 **Example 2:** 

```
Input: root = [1,2]
Output: 1

```

 

 **Constraints:** 

- The number of nodes in the tree is in the range [1, 104].
- -100 <= Node.val <= 100

## Solution

**Language:** Python  
**Runtime:** 6 ms (beats 26.85%)  
**Memory:** 22.1 MB (beats 89.08%)  
**Submitted:** 2026-09-01T16:45:47.400Z  

```py
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

```

---

[View on LeetCode](https://leetcode.com/problems/diameter-of-binary-tree/)