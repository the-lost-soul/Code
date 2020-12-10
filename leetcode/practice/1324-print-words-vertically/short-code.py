class Solution:
    def printVertically(self, s: str) -> List[str] :
        words = s.split(' ')
        # Generator Comprehension
        maxLen = max(len(w) for w in words)
        ans = [(''.join([w[i] if i < len(w) else ' 'for w in words]).rstrip())
               for i in range(maxLen)]
        return ans
