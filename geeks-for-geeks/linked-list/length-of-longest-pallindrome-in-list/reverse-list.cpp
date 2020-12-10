int getLength(Node* head1 , Node* head2)
{
    int count = 0 ;
    while(head1 and head2)
    {
        if(head1->data == head2->data)
            count += 2 ;
        else break ;
        head1 = head1->next ;
        head2 = head2->next ;
    }
    return count ;
}
/*The function below returns an int denoting
the length of the longest palindrome list. */
int maxPalindrome(Node *head)
{
    Node* prev = nullptr ;
    Node* curr = head ;
    int ans = INT_MIN ;
    while(curr)
    {
        Node* next = curr->next ;
        curr->next = prev ;
        // Get odd length pallindrome having center at curr
        ans = max(ans , getLength(prev , next) + 1) ;
        
        // Get even length pallindrome beginning from curr and next
        ans = max(ans , getLength(curr , next)) ;
        prev = curr ;
        curr = next ;
    }
    return ans ;
}
