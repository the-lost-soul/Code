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
    int getDecimalValue(ListNode* head) ;
};

int Solution :: getDecimalValue(ListNode* head)
{
    int currTotal = 0 ;
    while(head)
    {
        currTotal = currTotal*2 + head->val ;
        head = head->next ;
    }
    return currTotal ;
}
