class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        hashData = collections.defaultdict(list)
        for string in paths :
            splitStr = string.split()
            directory = splitStr[0]
            for files in splitStr[1:] :
                fileName , waste , data = files.partition('(')
                hashData[data[:-1]].append(directory + '/' + fileName)
        
        return [x for x in hashData.values() if len(x) > 1]
