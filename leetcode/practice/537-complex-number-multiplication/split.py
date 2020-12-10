class Solution:
    def complexNumberMultiply(self, a: str, b: str) -> str:
        
        def splitCompNum(num) :
            real, imag = num.split('+')
            imag , _ = imag.split('i')
            return int(real) , int(imag)
        
        real1 , imag1 = splitCompNum(a)
        real2 , imag2 = splitCompNum(b)
        
        real = real1*real2 - imag1*imag2
        imag = real1*imag2 + real2*imag1
        return "{}+{}i".format(real , imag)
