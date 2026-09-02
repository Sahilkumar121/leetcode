import sys


def solve(it) -> str:
    # write code here
    n = int(next(it))

    one_kg = n * 20
    two_kg = ((n // 2) * 30) + ((n % 2) * 20)

    return str(max(one_kg, two_kg))

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