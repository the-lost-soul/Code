bool isPallindromeUtil(Node** headRef , Node* head)
{
    if(!head)return true ;
    bool check = isPallindromeUtil(headRef , head->next) ;
    if(((*headRef)->data == head->data) and check)
    {
        (*headRef) = (*headRef)->next ;
        return true ;
    }
    return false ;
    
}
/*You are required to complete this method */
bool isPalindrome(Node *head)
{
    Node** headRef = &head ;
    return isPallindromeUtil(headRef , head) ;
}
