class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        c = Counter(ransomNote)
        d = Counter(magazine)
        c.subtract(d)
        return all(v <= 0 for v in c.values()) 
