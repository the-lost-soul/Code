class Solution {
public:
    string minRemoveToMakeValid(string s) ;
};
/* Idea is same as the Balanced Parenthesis */
/* Keep track of all the indices which are making
 * the string unbalanced .
 */
string Solution :: minRemoveToMakeValid(string s)
{
    unordered_set<int>remove ;
    stack<int>myStack ;
    int len = s.length() ;
    for(int i = 0 ; i < len ; i++)
    {
        if(s[i] == '(')myStack.push(i) ;
        else if(s[i] == ')')
        {
            if(myStack.empty())remove.insert(i) ;
            else myStack.pop() ;
        }
    }
    while(!myStack.empty())
    {
        int removeInd = myStack.top() ;
        remove.insert(removeInd) ;
        myStack.pop() ;
    }
    
    string answer = "" ;
    for(int i = 0 ; i < len ; i++)
    {
        if(remove.find(i) == remove.end())
        {
            answer += s[i] ;
        }
    }
    return answer ;
}
