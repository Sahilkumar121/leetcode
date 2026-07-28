class Solution:
    def smallestPalindrome(self, s: str) -> str:
        if len(s) == 1:
            return s

        alphabates: list[int] = [0] * 26

        for character in list(s):
            alphabates[ord(character) - 97] += 1

        lexi_smallest_string = [""] * len(s)

        pointer = 0
        middle_chr = ""

        for index, value in enumerate(alphabates):
            if value % 2 != 0:
                middle_chr = chr(index + 97)

            for _ in range(value // 2):
                char_to_place = chr(index + 97)
                lexi_smallest_string[pointer] = lexi_smallest_string[
                    len(lexi_smallest_string) - pointer - 1
                ] = char_to_place
                pointer += 1

        if len(s) % 2 != 0:
            lexi_smallest_string[len(s) // 2] = middle_chr

        return "".join(lexi_smallest_string)