class Solution:
    def printVertically(self, s: str) -> List[str] :
        words = s.split(' ')
        # Generator Comprehension
        maxLen = max(len(w) for w in words)
        ans = []
        for i in range(maxLen) :
            temp = []
            for w in words :
                if i < len(w) : temp.append(w[i])
                else : temp.append(' ')
            ans.append(''.join(temp).rstrip())
        return ans
                    
