class Solution:
    def isHappy(self, n: int) -> bool:
        
        def getNum(num) :
            temp = 0
            while(num != 0) :
                remainder = num%10
                temp += remainder**2
                num = num//10
            return temp
        
        slow = fast = n          
        while True :
            slow = getNum(slow)
            fast = getNum(fast)
            fast = getNum(fast)
            
            # If number is happy
            if fast == 1 or slow == 1 :
                break
            # If number is not happy , then there will be a cycle
            if fast == slow :
                return False
        return True
