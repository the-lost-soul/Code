/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k)
    {
        ListNode* curr = head ;
        int size = 0 ;
        while(curr)
        {
            curr = curr->next ;
            size++ ;
        }

        int width = size/k , remainder = size%k ;
        curr = head ;
        ListNode* prev = nullptr ;

        vector<ListNode*>ans(k , nullptr) ;
        for(int i = 0 ; curr and i < k ; i++ , remainder--)
        {
            ans[i] = curr ;
            for(int j = 0 ; j < width + (remainder > 0) ; j++)
            {
                prev = curr ;
                curr = curr->next ;
            }

            prev->next = nullptr ;
        }
       return ans ; 
    }
};
