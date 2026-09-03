# Kth Smallest Element in a BST

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the `root` of a binary search tree, and an integer `k`, return  *the*  `kth`  *smallest value (**1-indexed**) of all the values of the nodes in the tree*.

 

 **Example 1:** 

```
Input: root = [3,1,4,null,2], k = 1
Output: 1

```

 **Example 2:** 

```
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3

```

 

 **Constraints:** 

- The number of nodes in the tree is n.
- 1 <= k <= n <= 104
- 0 <= Node.val <= 104

 

 **Follow up:**  If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?

## Solution

**Language:** Python  
**Runtime:** 1 ms (beats 37.41%)  
**Memory:** 22.1 MB (beats 61.71%)  
**Submitted:** 2026-09-03T17:27:59.451Z  

```py
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
```

---

[View on LeetCode](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)