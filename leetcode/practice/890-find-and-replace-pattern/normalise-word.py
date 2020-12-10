class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        def normalise(s) :
            myDict = {}
            return [myDict.setdefault(ch , len(myDict)) for ch in s]
        normalisePatt = normalise(pattern)
        print(normalisePatt)
        return [w for w in words if normalisePatt == normalise(w)]
                
