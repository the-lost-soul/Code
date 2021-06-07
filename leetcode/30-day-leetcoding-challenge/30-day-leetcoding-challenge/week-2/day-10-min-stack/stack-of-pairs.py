class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.minStack = []
        

    def push(self, x: int) -> None :
        if not self.minStack : self.minStack.append((x , x))
        else : 
            self.minStack.append((x , min(x , self.minStack[-1][1])))
        

    def pop(self) -> None:
        if self.minStack :
            self.minStack.pop()
        

    def top(self) -> int :
        return self.minStack[-1][0]
        

    def getMin(self) -> int :
        return self.minStack[-1][1]
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
