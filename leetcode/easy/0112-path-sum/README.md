# Path Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given the `root` of a binary tree and an integer `targetSum`, return `true` if the tree has a  **root-to-leaf**  path such that adding up all the values along the path equals `targetSum`.

A  **leaf**  is a node with no children.

 

 **Example 1:** 

```
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.

```

 **Example 2:** 

```
Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There are two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.

```

 **Example 3:** 

```
Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.

```

 

 **Constraints:** 

- The number of nodes in the tree is in the range [0, 5000].
- -1000 <= Node.val <= 1000
- -1000 <= targetSum <= 1000

## Solution

**Language:** Python  
**Runtime:** 3 ms (beats 27.89%)  
**Memory:** 20.3 MB (beats 21.65%)  
**Submitted:** 2026-09-04T18:46:03.715Z  

```py
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root:
            return False

        def solve(root: TreeNode | None, sum: int, target: int) -> bool:
            if not root:
                return False

            if not root.left and not root.right and root.val + sum == target:
                return True

            return solve(root.left, root.val + sum, target) or solve(
                root.right, root.val + sum, target
            )

        return solve(root, 0, targetSum)
```

---

[View on LeetCode](https://leetcode.com/problems/path-sum/)