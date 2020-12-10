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
    // Since last word won't be pushed to stack so 
    // we have to do that explicitly , because till
    // we extract last word our while loop above
    // will terminate .
    myStack.push(temp) ;
    index = 0 ;
    int tempIndex = 0 ;
  
    while(!myStack.empty())
    {
        cout << myStack.top() ;
        myStack.pop() ;
    }
}
