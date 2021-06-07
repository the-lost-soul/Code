class Solution:
    def customSortString(self, S: str, T: str) -> str :
        count = collections.Counter(T)
        ans = []
        for ch in S :
            if count[ch] :
                ans.extend(ch*count.pop(ch))
        for ch , val in count.items() :
            ans.extend(ch*val)
        return ''.join(ans)
