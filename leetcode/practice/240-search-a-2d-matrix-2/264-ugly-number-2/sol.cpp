class Solution
{
public:
    int nthUglyNumber(int n)
    {
        if(n == 0) return 0 ;
        vector<int>ugly(n) ;
        ugly[0] = 1 ;

        int idx2 = 0 , idx3 = 0 , idx5 = 0 ;
        for(int i = 1 ; i < n ; i++)
        {
            int a2 = ugly[idx2]*2 ;
            int a3 = ugly[idx3]*3 ;
            int a5 = ugly[idx5]*5 ;
            
            int currUglyNum = min(a2 , min(a3 , a5)) ;
            
            if(currUglyNum == a2) idx2++ ;
            if(currUglyNum == a3) idx3++ ;
            if(currUglyNum == a5) idx5++ ;

            ugly[i] = currUglyNum ;
        }
       return ugly[n - 1] ; 
    }
};
