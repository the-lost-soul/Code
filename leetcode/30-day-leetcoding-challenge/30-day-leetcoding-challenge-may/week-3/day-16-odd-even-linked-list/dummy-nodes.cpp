class Solution {
public:
    ListNode* oddEvenList(ListNode* head) ;
};

ListNode* Solution :: oddEvenList(ListNode* head)
{
    if(!head || !head->next)return head ;
    ListNode* evenHead = new ListNode() ;
    ListNode* oddHead = new ListNode() ;
    ListNode* evenNode = evenHead ;
    ListNode* oddNode = oddHead ;
    int count = 1 ;
    while(head)
    {
        if(count % 2 == 0)
        {
            evenNode->next = head ;
            evenNode = evenNode->next ; ;
        }
        else
        {
            oddNode->next = head ;
            oddNode = oddNode->next ;
        }
        head = head->next ;
        count++ ;
    }
    oddNode->next = evenHead->next ;
    evenNode->next = NULL ;
    return oddHead->next ;
    
}
