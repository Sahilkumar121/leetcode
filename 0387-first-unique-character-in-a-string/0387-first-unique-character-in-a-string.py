class Solution:
    def firstUniqChar(self, s: str) -> int:
        freq = Counter(s)
        first_index = -1

        for index, letter in enumerate(list(s)):
            if freq[letter] == 1:
                first_index = index
                break
        return first_index