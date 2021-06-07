class Solution(object):
    def bitwiseComplement(self, N):
        num = 1
        while N > num :
            num = num*2 + 1
        return N^num
