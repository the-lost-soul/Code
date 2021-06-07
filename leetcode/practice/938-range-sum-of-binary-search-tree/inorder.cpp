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
    int rangeSumBST(TreeNode* root, int L, int R) ;
};

int Solution :: rangeSumBST(TreeNode* root , int L , int R)
{
    stack<TreeNode*>myStack ;
    myStack.push(root) ;
    int ans = 0 ;
    while(!myStack.empty())
    {
        TreeNode* node = myStack.top() ;
        myStack.pop() ;
        if(node->val <= R and node->val >= L)
        {
            ans += node->val ;
        }
        if(node->right)
            myStack.push(node->right) ;
        if(node->left)
            myStack.push(node->left) ;
    }
    return ans ;
}
