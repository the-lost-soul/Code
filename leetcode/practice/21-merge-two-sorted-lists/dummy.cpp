/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) ;
    
};

ListNode* Solution :: mergeTwoLists(ListNode* l1 , ListNode* l2)
{
    // A Dummy Node  whose "next" field contains the address of
    // merged lists .
    ListNode dummy(INT_MAX) ;
    
    // From this node we link the required nodes of given lists .
    ListNode* head = &dummy ;
    
    while(l1 or l2)
    {
        if(!l1)
        {
            head->next = l2 ;
            break ;
        }
        else if(!l2)
        {
            head->next = l1 ;
            break ;
        }
        else if(l1->val < l2->val)
        {
            head->next = l1 ;
            head = head->next ;
            l1 = l1->next ;
        }
        else
        {
            head->next = l2 ;
            head = head->next ;
            l2 = l2->next ;
        }
    }
    
    // This contains the address of resultant merged lists .
    return dummy.next ;
}
