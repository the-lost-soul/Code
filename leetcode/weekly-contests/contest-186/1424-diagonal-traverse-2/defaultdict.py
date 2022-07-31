class Solution:
    def findDiagonalOrder(self, nums: List[List[int]]) -> List[int]:
        myDict = collections.defaultdict(list)
        for i in range(len(nums)) :
            for j in range(len(nums[i])) :
                myDict[i + j].append(nums[i][j])
        
        return [ele for key in myDict for ele in reversed(myDict[key])]
