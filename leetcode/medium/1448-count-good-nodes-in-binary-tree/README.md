# Count Good Nodes in Binary Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a binary tree `root`, a node  *X*  in the tree is named  **good**  if in the path from root to  *X*  there are no nodes with a value  *greater than*  X.

Return the number of  **good**  nodes in the binary tree.

 

 **Example 1:** 

```
Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.
```

 **Example 2:** 

```
Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.
```

 **Example 3:** 

```
Input: root = [1]
Output: 1
Explanation: Root is considered as good.
```

 

 **Constraints:** 

- The number of nodes in the binary tree is in the range [1, 10^5].
- Each node's value is between [-10^4, 10^4].

## Solution

**Language:** Python  
**Runtime:** 153 ms (beats 5.13%)  
**Memory:** 32.1 MB (beats 18.17%)  
**Submitted:** 2026-09-04T16:56:15.755Z  

```py
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        self.goodNode = 0

        def checkGoodNode(root: TreeNode | None, max_num: int) -> None:
            if not root:
                return

            if root.val >= max_num:
                self.goodNode += 1

            checkGoodNode(root.left, max(root.val, max_num))
            checkGoodNode(root.right, max(root.val, max_num))

        checkGoodNode(root, -(10**4) - 1)
        return self.goodNode
```

---

[View on LeetCode](https://leetcode.com/problems/count-good-nodes-in-binary-tree/)