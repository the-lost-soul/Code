class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        def selfDividing(ele) :
            for ch in str(ele) :
                if ch == '0' :
                    return False ;
                
                if ele%int(ch) != 0 :
                    return False 
                
            return True
        ans = []
        for ele in range(left , right + 1) :
            if ele < 10 :
                ans.append(ele)
            elif selfDividing(ele) :
                ans.append(ele)
            
        return ans
