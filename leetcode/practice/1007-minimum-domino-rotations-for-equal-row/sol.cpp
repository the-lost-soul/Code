class Solution {
public:
    int minDominoRotations(vector<int>& diceA , vector<int>& diceB) ;
    int getSwapCount(vector<int>& diceA , vector<int>& diceB , int val) ;
};

int Solution :: getSwapCount(vector<int>& diceA , vector<int>& diceB , int val)
{
    int swapA = 0 , swapB = 0 ;
    for(int i = 0 ; i < diceA.size() ; i++)
    {
        if(diceA[i] != val and diceB[i] == val)
        {
            swapA++ ;
        }
        
        if(diceA[i] == val and diceB[i] != val)
        {
            swapB++ ;
        }
        if(diceA[i] != val and diceB[i] != val)
        {
            return -1 ;
        }
    }
    return min(swapA , swapB) ;
}

int Solution :: minDominoRotations(vector<int>& diceA , vector<int>& diceB)
{
    vector<int>countA(7 , 0) , countB(7 , 0) ;
    for(int i = 0 ; i < diceA.size() ; i++)
    {
        countA[diceA[i]]++ ;
        countB[diceB[i]]++ ;
    }
    bool atleastOneAns = false ;
    int ans = INT_MAX ;
    for(int i = 1 ; i < 7 ; i++)
    {
        if(countA[i] + countB[i] >= diceA.size())
        {
            atleastOneAns = true ;
            ans = min(ans , getSwapCount(diceA , diceB , i)) ;
        }
    }
    if(atleastOneAns == false)return -1 ;
    return ans ;
}
