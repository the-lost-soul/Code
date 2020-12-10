void rearrange(struct Node *odd)
{
    if(!odd or !odd->next or !odd->next->next)return ;
    Node* even = odd->next ;
    // Remove the even nde link .
    odd->next = odd->next->next ;
    odd = odd->next ;
    Node* prev = nullptr ;
    even->next = prev ;
    prev = even ;
    while(odd and odd->next)
    {
        Node* temp = odd->next->next ;
        // Add the current even node as head of the even list .
        even = odd->next ;
        even->next = prev ;
        prev = even ;
        
        // Remove the even node link ,and make a link between
        // odd nodes .
        odd->next = temp ;
        if(temp)odd = temp ;
    }
    odd->next = even ;
    
}

