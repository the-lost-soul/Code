class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]] :
        candidates.sort()
        res = []
        def helper(temp , ind , currSum) :
            if currSum == target :
                res.append(temp)
                return 
            if currSum > target or ind >= len(candidates) :
                return 
            for i in range(ind , len(candidates)) :
                if candidates[i] > target :
                    return 
                if(i != 0 and i > ind and candidates[i] == candidates[i - 1]) :
                    continue
                helper(temp + [candidates[i]] , i + 1 , currSum + candidates[i])                    
        
        helper([] , 0 , 0)
        return res
