import sys
import math

def solve(it):
    # Write your code here
    x = int(next(it))
    y = int(next(it))
    z = int(next(it))

    if z - y == 0:
        return "-1"

    return str(math.ceil(((x+z) - y) / (z-y)) - 1)

if __name__ == '__main__':
    # Fast I/O

    data = sys.stdin.buffer.read().split()

    it = iter(data)

    # test case input
    # when no test case
    # t = 1
    t = int(next(it))

    result = []
    for _ in range(t):
        result.append(solve(it))

    sys.stdout.write("\n".join(result) + "\n")
