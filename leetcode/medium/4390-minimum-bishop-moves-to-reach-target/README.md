# Q1. Minimum Bishop Moves to Reach Target

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

There is an `8 x 8` empty chessboard with  **1-indexed**  rows and columns.

You are given an array `source = [sr, sc]` representing the starting position of a  **bishop**, and an array `target = [tr, tc]`. In one move, the bishop travels any number of squares along a single  **diagonal**  direction, staying within the board.

Return the  **minimum**  number of moves for the bishop to land  **exactly**  on `target`. If it can never reach `target`, return -1.

 

 **Example 1:** 

 **Input:**  source = [8,1], target = [1,8]

 **Output:**  1

 **Explanation:** 

 **​​​​​​​** 

A single diagonal move takes the bishop straight from `(8, 1)` to `(1, 8)`.

 **Example 2:** 

 **Input:**  source = [4,2], target = [1,3]

 **Output:**  2

 **Explanation:** 

The bishop moves from `(4, 2)` to `(3, 1)`, then from `(3, 1)` to `(1, 3)`, reaching the target in 2 moves.

 **Example 3:** 

 **Input:**  source = [1,1], target = [3,4]

 **Output:**  -1

 **Explanation:** 

No matter how many diagonal moves it makes, the bishop starting at `(1, 1)` can never land on `(3, 4)`. Thus, the answer is -1.

 

 **Constraints:** ​​​​​​​

- source.length == target.length == 2
- 1 <= sr, sc, tr, tc <= 8
- source != target

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 50.4 MB (beats 62.50%)  
**Submitted:** 2026-08-29T15:04:33.547Z  

```cpp
class Solution {
public:
    char checkColor(int x, int y)
    {
        if ((x == y) || (x % 2 == 0 && y % 2 == 0) || (x % 2 != 0 && y % 2 != 0))
        {
            return 'w';
        }

        return 'b';
    }
    
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        if (target[0] == source[0] && target[1] == source[1]) {
            return 0;
        }

        if (checkColor(source[0], source[1]) ==
            checkColor(target[0], target[1])) {
            for (int i = 1; i <= 8; i++) {
                if (source[0] + i == target[0] && source[1] + i == target[1] ||
                    (source[0] + i == target[0] &&
                     source[1] - i == target[1]) ||
                    (source[0] - i == target[0] &&
                     source[1] + i == target[1]) ||
                    (source[0] - i == target[0] &&
                     source[1] - i == target[1])) {
                    return 1;
                }
            }

            return 2;
        }

        return -1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-bishop-moves-to-reach-target/)