class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) ;
};
bool Solution :: canThreePartsEqualSum(vector<int>& A)
{
    int sum = accumulate(A.begin() , A.end() , 0) ;
    if(sum%3 != 0)return false ;
    bool firstArray = false ;
    bool secondArray = false ;
    bool thirdArray = false ;
    int firstSum = sum/3 ;
    int prefixSum = 0 ;
    for(int i = 0 ; i < A.size() ; i++)
    {
        prefixSum += A[i] ;
        if(!firstArray and prefixSum == firstSum)firstArray = true ;
        else if(firstArray and !secondArray and prefixSum == 2*firstSum)
            secondArray = true ;
        else if(firstArray and secondArray and prefixSum == 3*firstSum)
            thirdArray = true ;
    }
    return firstArray and secondArray and thirdArray ;
}
