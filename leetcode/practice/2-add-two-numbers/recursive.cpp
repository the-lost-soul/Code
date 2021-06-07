class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) ;
    ListNode * addNumbers(ListNode * l1 , ListNode * l2 , int carry) ;
};
ListNode * Solution :: addTwoNumbers(ListNode * l1 , ListNode * l2)
{
    int carry  = 0 ;
    return addNumbers(l1 , l2 , carry) ;
}
ListNode * Solution :: addNumbers(ListNode * l1 , ListNode * l2 , int carry)
{
    int sum = 0 ;
    if(!l1 and !l2)
    {
        if(carry > 0) sum = carry ;
        else return NULL ;
        
    }
    else if(!l1)
    {
        sum = l2->val + carry ;
    }
    else if(!l2)
    {
        sum = l1->val + carry ;
    }
    else sum = l1->val + l2->val + carry ;
    if(sum >= 10)
    {
        carry = sum / 10 ;
        sum = sum % 10 ;
    }
    ListNode * newHead = new ListNode(sum) ;
    if(!l1 and l2) newHead->next = addNumbers(l1 , l2->next , carry) ;
    else if(l1 and !l2) newHead->next = addNumbers(l1->next , l2 , carry) ;
    else if(l1 and l2) newHead->next = addNumbers(l1->next , l2->next , carry) ;
        
    return newHead ;
}
