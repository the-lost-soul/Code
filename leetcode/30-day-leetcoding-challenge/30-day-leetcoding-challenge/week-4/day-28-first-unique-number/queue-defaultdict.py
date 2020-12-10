class FirstUnique:

    def __init__(self, nums: List[int]):
        self.myDict = collections.defaultdict(int)
        self.queue = collections.deque()
        for ele in nums :
            self.myDict[ele] += 1
            self.queue.append(ele)            
        

    def showFirstUnique(self) -> int:
        while(self.queue and self.myDict[self.queue[0]] > 1) :
            self.queue.popleft()
        return -1 if not self.queue else self.queue[0]

    def add(self, value: int) -> None:
        self.myDict[value] += 1
        self.queue.append(value)
        


# Your FirstUnique object will be instantiated and called as such:
# obj = FirstUnique(nums)
# param_1 = obj.showFirstUnique()
# obj.add(value)
