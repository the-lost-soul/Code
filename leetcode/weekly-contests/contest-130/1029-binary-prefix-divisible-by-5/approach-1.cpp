class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) ;
};

vector<bool> Solution :: prefixesDivBy5(vector<int>& A)
{
    int number = 0 ;
    vector<bool>answer ;
    for(auto ele : A)
    {
        // To avoid overflow
        number = (number*2 + ele)%5 ;
        if(number == 0)answer.push_back(true) ;
        else answer.push_back(false) ;
    }
    
    return answer ;
}
