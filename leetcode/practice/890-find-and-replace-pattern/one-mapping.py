class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        ans = []
        for w in words :
            if len(set(w)) != len(set(pattern)) :
                continue
            
            if len(set(zip(w , pattern))) != len(set(pattern)) :
                continue
            ans.append(w)
        return ans
