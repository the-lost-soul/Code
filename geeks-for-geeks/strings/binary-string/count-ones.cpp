/* The idea is simple , here we have to find the number of ways
 * we can choose two 1's , which is nothing but nC2 i.e n*(n-1)/2 .
 */
long binarySubstring(int n , string str)
{
    int onesCount = 0 ;
    int len = str.length() ;
    int index = 0 ;
    while(index < len)
    {
        if(str[index] == '1')onesCount++ ;
        index++ ;
    }
    return (onesCount*(onesCount-1))/2 ;
}
