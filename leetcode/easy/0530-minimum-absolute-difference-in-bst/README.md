# Minimum Absolute Difference in BST

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given the `root` of a Binary Search Tree (BST), return  *the minimum absolute difference between the values of any two different nodes in the tree*.

 

 **Example 1:** 

```
Input: root = [4,2,6,1,3]
Output: 1

```

 **Example 2:** 

```
Input: root = [1,0,48,null,null,12,49]
Output: 1

```

 

 **Constraints:** 

- The number of nodes in the tree is in the range [2, 104].
- 0 <= Node.val <= 105

 

 **Note:**  This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/

## Solution

**Language:** Python  
**Runtime:** 4 ms (beats 37.37%)  
**Memory:** 21 MB (beats 31.30%)  
**Submitted:** 2026-09-08T14:51:49.544Z  

```py
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
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-absolute-difference-in-bst/)