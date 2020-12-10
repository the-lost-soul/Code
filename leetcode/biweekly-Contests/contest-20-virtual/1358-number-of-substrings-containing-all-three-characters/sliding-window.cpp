class Solution {
public:
    int numberOfSubstrings(string str) ;
};

int Solution :: numberOfSubstrings(string str)
{
    vector<int>arr(3 , 0) ;
    int len = str.length() , count = 0 ;
    int j = -1 , i = 0 ;
    while(j < i)
    {
        if(arr[0] > 0 && arr[1] > 0 && arr[2] > 0)
        {
            count += (len - i + 1) ;
            j++ ;
            arr[str[j] - 'a']-- ;
        }
        else
        {
            if(i < len)
            {
                arr[str[i] - 'a']++ ;
                i++ ;
            }
            else return count ;
        }
    }
    return count ;  
}
