class Solution:
    def toLowerCase(self, str: str) -> str:
        return "".join(chr(ord(ch) + 32) if "A" <= ch <= "Z" else ch for ch in str)
