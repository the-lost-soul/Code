class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        myDict = {} 
        for ind , ch in enumerate(S) :
            myDict[ch] = ind
        
        ans = []
        # Remember don't assign use two statements at a single line
        # Error - a = 0 , b = 0
        # Correct - a , b = 0 , 0
        # Or do it like the below 2 assignments
        j = 0 
        start = 0
        for i , ch in enumerate(S) :
            j = max(j , myDict[ch])
            if i == j :
                ans.append(i - start + 1)
                start = i + 1
        return ans
        
