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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) ;
};

TreeNode* Solution :: getTargetCopy(TreeNode* original , TreeNode* cloned , TreeNode* target)
{
    queue<TreeNode*>myQueue ;
    myQueue.push(cloned) ;
    while(!myQueue.empty())
    {
        TreeNode* node = myQueue.front() ;
        myQueue.pop() ;
        if(node->val == target->val)
        {
            TreeNode* leftTC = target->left , *rightTC = target->right ;
            TreeNode* leftCLC = node->left , *rightCLC = node->right ;
            int targetLC = INT_MAX ;
            int targetRC = INT_MAX ;
            int originalLC = INT_MAX ;
            int originalRC = INT_MAX ;
            if(leftTC) targetLC = leftTC->val ;
            if(rightTC) targetRC = rightTC->val ;
            if(leftCLC) originalLC = leftCLC->val ;
            if(rightCLC) originalRC = rightCLC->val ;
            if(targetLC == originalLC and targetRC == originalRC)
            {
                return node ;
            }
        }
        
        if(node->left) myQueue.push(node->left) ;
        if(node->right) myQueue.push(node->right) ;
    }
    return nullptr ;
}
