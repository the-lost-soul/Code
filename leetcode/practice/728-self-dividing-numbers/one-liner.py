class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        return [ele for ele in range(left , right + 1) 
                if all([int(ch) != 0 and ele%int(ch) == 0 for ch in str(ele)])]
