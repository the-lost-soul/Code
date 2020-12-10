class Solution {
public:
    int minDominoRotations(vector<int>& diceA , vector<int>& diceB) ;
};
int Solution :: minDominoRotations(vector<int>& diceA , vector<int>& diceB)
{
    vector<int>countA(7 , 0) , countB(7 , 0) , same(7 , 0) ;
    for(int i = 0 ; i < diceA.size() ; i++)
    {
        countA[diceA[i]]++ ;
        countB[diceB[i]]++ ;
        same[diceA[i]] += diceA[i] == diceB[i] ? 1 : 0 ;
        
    }
    for(int i = 1 ; i < 7 ; i++)
    {
        if(countA[i] + countB[i] - same[i] == diceA.size())
            return diceA.size() - max(countA[i] , countB[i]) ;
    }
    return -1 ;
}
