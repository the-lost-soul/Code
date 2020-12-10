class Solution:
    def minSteps(self, s: str, t: str) -> int:
        countS = collections.Counter(s)
        countT = collections.Counter(t)
        res = 0
        for ch in string.ascii_lowercase :
            res += countS[ch] - countT[ch] if countS[ch] > countT[ch] else 0
        return res
