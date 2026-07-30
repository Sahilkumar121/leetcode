class Solution:
    def minimumPushes(self, word: str) -> int:
        if len(word) <= 8:
            return len(word)
        
        min_num = 0
        
        stack = len(word) // 8
        remainder = len(word) % 8
        
        for i in range(1, stack+1):
            min_num += (i * 8)
        
        min_num += (remainder * (stack + 1))
        
        return min_num