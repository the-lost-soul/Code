class Solution:
    def minIncrementForUnique(self, arr: List[int]) -> int:
        arr.sort()
        increments = 0
        for i in range(1 , len(arr)) :
            if arr[i - 1] >= arr[i] :
                increments += arr[i - 1] - arr[i] + 1
                arr[i] = arr[i - 1] + 1
            
        return increments
