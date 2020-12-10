class Solution:
    def partitionDisjoint(self, arr: List[int]) -> int:
        disjointLen = 1
        currMax = maxLeft = arr[0]
        for i , ele in enumerate(arr) :
            currMax = max(currMax , ele) 
            if maxLeft > ele :
                maxLeft = currMax
                disjointLen = i + 1
        return disjointLen
