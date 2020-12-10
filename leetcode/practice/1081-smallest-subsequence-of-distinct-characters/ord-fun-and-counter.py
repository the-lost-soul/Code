class Solution:
    def smallestSubsequence(self, text: str) -> str:
        count = Counter(text)
        visited = [False]*26
        ans = []
        for ch in text :
            if visited[ord(ch) - 97] :
                count[ch] -= 1
                continue
            
            while(len(ans) > 0 and ans[-1] >= ch and count[ans[-1]] > 0) :
                visited[ord(ans[-1]) - 97] = False
                ans.pop()
            
            ans.append(ch)
            visited[ord(ch) - 97] = True
            count[ch] -= 1
        
        return "".join(ans)
