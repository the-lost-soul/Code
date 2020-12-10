void reverseWords(char *s) 
{
    stack<string>myStack ;
    string temp = "" ;
    int index = 0 ;
    while(s[index] != '\0')
    {
        if(s[index] == '.')
        {
            myStack.push(temp) ;
            myStack.push(".") ;
            temp ="" ;
        }
        else temp += s[index] ;
        index++ ;
    }
    /* Since last word won't be pushed to stack so 
     * we have to do that explicitly , because after
     * the last word while loop will terminate as it
     * will get a termination character , hence we won't
     * be able to push our word to stack .
     */
    myStack.push(temp) ;
    index = 0 ;
    temp = "" ;
    // copy everything back to temp string .
    while(!myStack.empty())
    {
        temp += myStack.top() ;
        myStack.pop() ;
    }
    // copy the reversed string to original char array .
    index = 0 ;
    while(temp[index] != '\0')
    {
        s[index] = temp[index] ;
        index++ ;
    }
    index = 0 ;
    while(s[index] != '\0')
    {
        cout << s[index++] ;
    }
}
