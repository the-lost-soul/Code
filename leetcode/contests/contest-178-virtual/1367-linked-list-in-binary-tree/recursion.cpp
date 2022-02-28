/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* head ;
    bool isSubPath(ListNode* head, TreeNode* root) ;
    bool helper(ListNode* head , TreeNode* root) ;
};

bool Solution :: helper(ListNode* head , TreeNode* root)
{
    if(head and !root)return false ;
    if(!head)return true ;
    
    return (head->val == root->val) and (helper(head->next , root->left) or helper(head->next , root->right)) ;
}

bool Solution :: isSubPath(ListNode* head , TreeNode* root)
{
    if(!root)return false ;
    return isSubPath(head , root->right) or isSubPath(head , root->left) or helper(head , root) ;
}
