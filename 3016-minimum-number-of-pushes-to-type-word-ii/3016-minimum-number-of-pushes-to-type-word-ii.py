class Solution:
    def minimumPushes(self, word: str) -> int:
        freq = Counter(word)

        sort_freq = dict(sorted(freq.items(), key=lambda item: item[1], reverse=True))

        n = len(sort_freq)
        min_opr = 0

        if n <= 8:
            for value in sort_freq.values():
                min_opr += value

            return min_opr

        stack = n // 8
        left_str = n % 8
        pointer = 0
        for i in range(1, stack + 1):
            for _ in range(8):
                min_opr += i * list(sort_freq.values())[pointer]
                pointer += 1

        for _ in range(left_str):
            min_opr += (stack + 1) * list(sort_freq.values())[pointer]
            pointer += 1

        return min_opr