/* std :: str.find(char) return the index where char is present else
 * it returns std::npos .
 */

class Solution {
public:
    string complexNumberMultiply(string a, string b) ;
    pair<int , int> splitComplexNum(string num) ;
};

pair<int , int> Solution :: splitComplexNum(string num)
{
    // Get the real part of given complex number as a string
    string r = num.substr(0 , num.find('+')) ;
    // Get the imaginary part of given complex nume as a string
    string i = num.substr(num.find('+') + 1) ;
    int real = r[0] == '-' ? -stoi(r.substr(1)) : stoi(r.substr(0)) ;
    int imag ;
    if(i[0] == '-')
    {
        imag = -stoi(i.substr(1 , i.find('i'))) ;
    }
    else
    {
        imag = stoi(i.substr(0 , i.find('i'))) ;
    }
    return {real , imag} ;
}
string Solution :: complexNumberMultiply(string cNum1 , string cNum2)
{
    pair<int , int>realAndImag1 = splitComplexNum(cNum1) ;
    pair<int , int>realAndImag2 = splitComplexNum(cNum2) ;
    
    int real1 = realAndImag1.first , imag1 = realAndImag1.second ;
    int real2 = realAndImag2.first , imag2 = realAndImag2.second ;
    int real = real1*real2 - imag1*imag2 ;
    int imaginary = real1*imag2 + real2*imag1 ;
    return to_string(real) + "+" + to_string(imaginary) + "i" ;
}
