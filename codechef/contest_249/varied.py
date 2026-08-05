import sys

def solve(it):
    # Write your code here
    num = int(next(it))
    prev = -1

    while num > 0:
        remainder = num % 10
        if remainder == prev:
            return "No"
        prev = remainder
        num //= 10

    return "Yes"

if __name__ == '__main__':
    # Fast I/O

    data = sys.stdin.buffer.read().split()

    it = iter(data)

    # test case input
    # when no test case
    t = 1
    # t = int(next(it))

    result = []
    for _ in range(t):
        result.append(solve(it))

    sys.stdout.write("\n".join(result) + "\n")

