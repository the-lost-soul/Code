class Solution:
    def findBestValue(self, arr: List[int], target: int) -> int:
        arr.sort(reverse = 1)
        
        tempAns = arr[0]
        while(arr and target > arr[-1]*len(arr)) :
            target -= arr.pop()
        
        if not arr :
            return tempAns
        
        return int(round((target - 0.0001)/len(arr)))
