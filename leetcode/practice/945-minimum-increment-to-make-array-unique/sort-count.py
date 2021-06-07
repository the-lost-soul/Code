class Solution:
    def minIncrementForUnique(self, arr: List[int]) -> int:
        arr.sort()
        count = collections.Counter(arr)
        used = []
        increments = 0
        for i in range(100000) :
            if count[i] >= 2 :
                used.extend([i]*(count[i] - 1))
            elif used and count[i] == 0 :
                increments += i - used.pop()
            
        return increments
