/* In this approach we have to fin pattern ("abc") in string s , if pattern
exists then we will erase that pattern and again find the pattern ,if for any
test case pattern doesn't exists then s.find() will return -1 and our while loop 
will terminate .
If at last string is empty then this means we have dleted all occurrences of the
pattern "abc" from given string and string is valid */

class Solution 
{
    public:
    bool isValid(string s) ;
};

bool Solution:: isValid(string s)
{
    string pattern = "abc" ;
    auto position = s.find(pattern) ;
    while(position != string :: npos)
    {
        s.erase(position , 3) ;
        position = s.find(pattern) ;
    }
    
    return s.empty() ;
}

