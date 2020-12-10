class Solution(object):
    def numSmallerByFrequency(self, queries, words):
        freq = [0]*11
        for word in words :
            freq[word.count(min(word))] += 1
        
        for i in range(1 , 11) :
            freq[i] += freq[i - 1]
        
        res = []
        for s in queries :
            freqCount = s.count(min(s))            
            res.append(freq[10] - freq[freqCount])
            
        return res
        
