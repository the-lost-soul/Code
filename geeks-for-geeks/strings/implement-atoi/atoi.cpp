int atoi(string str)
{
    int len = str.length() ;
    int num = 0 ;
    bool negative = false ;
    for(int i = 0 ; i < len ; i++)
    {
        if(str[i] == '-')negative = true ;
        else if(str[i] >= '0' and str[i] <= '9')
            num = num*10 + str[i] -'0' ;
        else return -1 ;
    }
    if(negative)
    return -num ;
    
    return num ;
}
