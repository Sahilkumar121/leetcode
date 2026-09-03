# Flatten Binary Tree to Linked List

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the `root` of a binary tree, flatten the tree into a "linked list":

- The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
- The "linked list" should be in the same order as a pre-order traversal of the binary tree.

 

 **Example 1:** 

```
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]

```

 **Example 2:** 

```
Input: root = []
Output: []

```

 **Example 3:** 

```
Input: root = [0]
Output: [0]

```

 

 **Constraints:** 

- The number of nodes in the tree is in the range [0, 2000].
- -100 <= Node.val <= 100

 

 **Follow up:**  Can you flatten the tree in-place (with `O(1)` extra space)?

## Solution

**Language:** Python  
**Runtime:** 3 ms (beats 10.90%)  
**Memory:** 19.8 MB (beats 5.22%)  
**Submitted:** 2026-09-03T16:25:55.725Z  

```py
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if not root:
            return

        self.preOrder: list[TreeNode] = []

        def findPreorder(root: TreeNode | None) -> TreeNode | None:

            if not root:
                return None

            self.preOrder.append(root)
            findPreorder(root.left)
            findPreorder(root.right)

        findPreorder(root)

        curr_node: TreeNode = root
        for i in range(1, len(self.preOrder)):
            curr_node.left = None
            curr_node.right = self.preOrder[i]

            curr_node = curr_node.right
```

---

[View on LeetCode](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)