void helper(deque<Node*> dq , int length , int& ans)
{
    if(dq.empty())
    {
        ans = max(ans , length) ;
        return ;
    }
    Node* start = dq.front() ;
    Node* end = dq.back() ;
    if(start == end)
    {
        ans = max(ans , length + 1) ;
        return ;
    }
    dq.pop_back() ;
    helper(dq , 0 , ans) ;
    dq.push_back(end) ;
    dq.pop_front() ;
    helper(dq , 0 , ans) ;
    dq.push_front(start) ;
    if(start->data == end->data)
    {
        dq.pop_back() ;
        dq.pop_front() ;
        helper(dq , length + 2 , ans) ;
    }
}
/*The function below returns an int denoting
the length of the longest palindrome list. */
int maxPalindrome(Node *head)
{
    deque<Node *> dq ;
    while(head)
    {
        dq.push_back(head) ;
        head = head->next ;
    }
    int length = 0 , ans = INT_MIN ;
    helper(dq , length , ans) ;
    return ans ;
}
