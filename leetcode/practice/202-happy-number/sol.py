class Solution:
    def isHappy(self, n: int) -> bool:
        happy = [False , True , False , False , False , False , False , True , False , False]
        while(n != 1) :
            num = 0
            while n != 0 :
                remainder = n%10
                n = n//10
                num += remainder**2
            n = num
            if n < 10 and happy[n] == False :
                return False
        return True
