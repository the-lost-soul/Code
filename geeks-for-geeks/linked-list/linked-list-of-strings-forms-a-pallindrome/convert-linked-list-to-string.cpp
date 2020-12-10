bool Compute(Node* root)
{
    string pallindrome = "" ;
    while(root)
    {
        pallindrome += root->data ;
        root = root->next ;
    }
    int len = pallindrome.length() ;
    for(int i = 0 ; i < len/2 ; i++)
    {
        if(pallindrome[i] != pallindrome[len - i - 1])return false ;
    }
    return true ;
}
