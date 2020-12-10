class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) ;
};

vector<bool> Solution :: prefixesDivBy5(vector<int>& A)
{
    int number = 0 ;
    for(int len = A.size() - 1 ; len >= 0 ; len --)
    {
        number += A[len]*pow(2 , A.size() - len - 1) ;
    }
    
    // DEBUGGING
    // cout<<number<<endl;
    vector<bool> answer(A.size()) ;
    
    int index = A.size() - 1 ;
    
    while(index >= 0)
    {
        if(number % 5 == 0)answer[index] = true ;
        else answer[index] = false ;
        
        number = number >> 1 ;
        
        // DEBUGGING
        // cout<<number<<endl ;
        
        index -- ;
    }
    
    
    return answer ;
}
