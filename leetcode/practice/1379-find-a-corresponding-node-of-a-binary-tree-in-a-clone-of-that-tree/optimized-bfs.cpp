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
    myQueue.push(original) ;
    while(!myQueue.empty())
    {
        TreeNode* nodeClone = myQueue.front() ;
        myQueue.pop() ;
        TreeNode* nodeReal = myQueue.front() ;
        myQueue.pop() ;
        if(nodeReal == target) return nodeClone ;
        if(nodeClone->left)myQueue.push(nodeClone->left) ;
        if(nodeReal->left) myQueue.push(nodeReal->left) ;
        if(nodeClone->right) myQueue.push(nodeClone->right) ;
        if(nodeReal->right)myQueue.push(nodeReal->right) ;
    }
    return nullptr ;
}
