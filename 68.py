from typing import List


class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:

        n: int = len(words)
        ans: List[str] = []
        i = 0

        while i < len(words):
            letter_count = len(words[i])
            j = i + 1

            while j < n and len(words[j]) + letter_count + (j - i) <= maxWidth:
                letter_count += len(words[j])
                j += 1

            sentence = ""
            numb_words = j - i
            space_between_words_count = numb_words - 1

            if j == n or numb_words == 1:
                sentence = " ".join(words[i:j])
                sentence += " " * (maxWidth - len(sentence))

            else:
                total_space = maxWidth - letter_count
                space_assign = total_space // space_between_words_count
                extra_space = total_space % space_between_words_count

                for p in range(i, j):
                    sentence += words[p]

                    if p < j - 1:
                        sentence += " " * space_assign
                        if p - i < extra_space:
                            sentence += " "

            i = j

            ans.append(sentence)

        return ans


def main():
    sol = Solution()

    print(
        sol.fullJustify(
            [
                "Science",
                "is",
                "what",
                "we",
                "understand",
                "well",
                "enough",
                "to",
                "explain",
                "to",
                "a",
                "computer.",
                "Art",
                "is",
                "everything",
                "else",
                "we",
                "do",
            ],
            maxWidth=20,
        )
    )


if __name__ == "__main__":
    main()
