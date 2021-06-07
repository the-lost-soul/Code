class Solution:
    def maximum69Number (self, num: int) -> int:
        temp = num
        ind , i = -1 , 0
        while temp != 0 :
            ind = i if temp%10 == 6 else ind
            temp //= 10
            i += 1
        return (num + 3*(10**ind) if ind != -1 else num)
