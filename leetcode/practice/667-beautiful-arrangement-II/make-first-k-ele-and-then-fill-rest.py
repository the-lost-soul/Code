class Solution:
    def constructArray(self, n: int, k: int) -> List[int]:
        res = [1]*n
        add = True
        fillFromHere = 0 
        maxEle = 0
        for i in range(1 , n) :
            res[i] = res[i - 1] + (k if add else -k)
            add = False if add else True
            k -= 1
            if k == 0 : 
                fillFromHere = i + 1
                maxEle = max(res)
        maxEle += 1
        for i in range(fillFromHere , n) :
            res[i] = maxEle
            maxEle += 1
        return res
            
