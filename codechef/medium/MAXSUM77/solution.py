import sys
from sys import maxunicode


def solve(it) -> str:
    # write code here
    n = int(next(it))
    k = int(next(it))

    nums: list[int] = []
    for _ in range(n):
        num = int(next(it))
        nums.append(num)

    window = n - k
    current_sum = sum(nums[:window])
    max_sum = current_sum

    for i in range(window, n):
        current_sum += nums[i] - nums[i-1]
        max_sum = max(max_sum, current_sum)

    return str(max_sum)


def main():
    input_data = sys.stdin.read().split()
    it = iter(input_data)

    # t = 1
    t = int(next(it)) # comment it when no test case given

    answer: list[str] = []
    for _ in range(t):
        answer.append(solve(it))

    sys.stdout.write("\n".join(answer) + "\n")


if __name__ == "__main__":
    main()