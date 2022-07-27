class Solution
{
public:
    bool isOneBitCharacter(vector<int>& bits)
    {
        int len = bits.size() ;
        int oneBitChar = -1 , i = 0 ;

        while(i < len)
        {
            if(bits[i] == 0)
            {
                oneBitChar = i + 1 ;
                i++ ;
            }
            else if(i + 1 < len)
                i += 2 ;
        }
        return oneBitChar == len ? true : false ;
    }
};
