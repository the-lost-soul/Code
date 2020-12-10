int isValid(char *ip)
{
    int dots = 0 ;
    int i = 0 ;
    while(ip[i] != '\0')
    {
        long long sum = 0 ;
        int j = i ;
        int firstIndOfCurrDecNum = i ;
        while(ip[j] != '.' and ip[j] != '\0')
        {
            // If the current character is not a digit , then
            // address is invalid .
            if(ip[j] >= '0' and ip[j] <= '9')
                sum = sum*10 + ip[j] - '0' ;
            else return 0 ;
            j++ ;
        }
        
        /* If current sum is zero and if any one of following holds -- 
         * 1 -- If difference of index of start and last of current
         *      decimal number is greater than 1 , then current
         *      decimal number is 0000 .
         * 2 -- If i == j then this means last index's char which is 
         *      nothing but  "." of prev decimal number and first index 
         *      i.e "." of current decimal number is same , then address 
         *      is invalid . eg -- 0.0..0 -->here index 3 and 4 have same
         *                   value which is "." , hence invalid .
         */
        if(sum == 0 and(j - i > 1 or j == i))return 0 ;
        
        if(ip[j] == '.')dots++ ;
        
        
        // If the current decimal number has a leading zero
        // then address is invalid .
        if(sum > 0 and ip[firstIndOfCurrDecNum] == '0')return 0 ;
        
        // If current decimal number is less than 0 or greater than
        // 255 then address is invalid .
        if(sum < 0 or sum > 255)return 0 ;
        if(ip[j] == '\0')break ;
        // Due to this seg-fault may occur , because once we do i = j + 1
        // and if j is last element then i will be pointing outside the
        // bound of char aray . So , use an if statement just above .
        i = j + 1;
    }
    // We may get a case when there is either less or more than 3 dots
    // in address which implies address is invalid .
    if(dots != 3)return 0 ;
    return 1 ;
}
