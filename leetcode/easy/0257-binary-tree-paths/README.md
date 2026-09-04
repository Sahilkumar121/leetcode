# Binary Tree Paths

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given the `root` of a binary tree.

Return all  **root-to-leaf**  paths in  **any order**.

A  **leaf**  is a node with no children.

 

 **Example 1:** 

```
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]

```

 **Example 2:** 

```
Input: root = [1]
Output: ["1"]

```

 

 **Constraints:** 

- The number of nodes in the tree is in the range [1, 100].
- -100 <= Node.val <= 100

## Solution

**Language:** Python  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 19.5 MB (beats 25.42%)  
**Submitted:** 2026-09-04T19:06:20.680Z  

```py
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
```

---

[View on LeetCode](https://leetcode.com/problems/binary-tree-paths/)