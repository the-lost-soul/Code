class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        myDict = {}
        for word in strs :
            tup = tuple(sorted(word))
            myDict[tup] = myDict.get(tup , []) + [word]
        return myDict.values()
