char *encode(char *src)
{
    string str = "" ;
    int i = 0 ;
    while(src[i] != '\0')
    {
        
        char ele = src[i] ;
        int j = i , count = 0 ;
        while(src[j] != '\0' and src[j] == ele)
        {
            j++ ;
            count++ ;
        }
        str = str + src[i] + to_string(count) ;
        i = j ;
    }
    for(int i = 0 ; i < str.length() ; i++)src[i] = str[i] ;
    // Terminate the source string .
    src[str.length()] = '\0' ;
    return src ;
}     
 
