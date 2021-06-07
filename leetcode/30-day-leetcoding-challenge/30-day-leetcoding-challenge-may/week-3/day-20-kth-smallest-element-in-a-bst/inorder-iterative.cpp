/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) ;
};

int Solution :: kthSmallest(TreeNode* root , int k)
{
    stack<TreeNode*>myStack ;
    TreeNode* node = root ;
    while(node or !myStack.empty())
    {
        while(node != nullptr)
        {
            myStack.push(node) ;
            node = node->left ;
        }
        
        TreeNode* curr = myStack.top() ;
        myStack.pop() ;
        int remaining = k - 1 ;
        k-- ;
        if(remaining == 0)return curr->val ;
        node = curr->right ;
    }
    return -1 ;
}
