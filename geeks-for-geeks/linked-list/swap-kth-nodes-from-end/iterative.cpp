// Should swap Kth node from beginning and Kth
// node from end in list and return new head.
Node *swapkthnode(Node* head, int num, int K)
{
    if(K > num)return head ;
    int left = K , right = num - K ;
    if(left == right + 1)return head ;
    Node* start = head ;
    Node* prevStart = nullptr ;
    while(left > 1)
    {
        prevStart = start ;
        start = start->next ;
        left-- ;
    }
    Node* end = head ;
    Node* prevEnd = nullptr ;
    while(right > 0)
    {
        prevEnd = end ;
        end = end->next ;
        right-- ;
    }
    if(prevStart)
    {
        prevStart->next = end ;
    }
    
    if(prevEnd)
    {
        prevEnd->next = start ;
    }
    Node* temp = end->next ;
    end->next = start->next ;
    start->next = temp ;
    if(K == 1)head = end ;
    if(K == num)head = start ;
    return head ;
}
