class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        myHeap = [-ele for ele in stones]
        heapq.heapify(myHeap)
        while len(myHeap) > 1 and myHeap[0] != 0 :
            stone1 = heapq.heappop(myHeap)
            stone2 = heapq.heappop(myHeap)
            heapq.heappush(myHeap , stone1 - stone2)
        
        return -myHeap[0]
