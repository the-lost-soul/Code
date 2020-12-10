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
    int longestZigZag(TreeNode* root) ;
    int helper(TreeNode* root , int direction , int length) ;
};

int Solution :: helper(TreeNode* root , int direction , int length)
{
    if(!root)return length ;
    if(direction == -1)
        return max(helper(root->right , 1 , length + 1) , helper(root->left , -1 , 0)) ;
    
    
    
    return max(helper(root->left , -1 , length + 1) , helper(root->right , 1 , 0)) ;
}

int Solution :: longestZigZag(TreeNode* root)
{
    return max(helper(root->left , -1 , 0) , helper(root->right , 1 , 0)) ;
}
