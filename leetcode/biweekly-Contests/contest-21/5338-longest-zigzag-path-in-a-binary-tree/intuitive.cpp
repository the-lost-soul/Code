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
    int helper(TreeNode* root , bool left) ;
};

int Solution :: helper(TreeNode* root , bool left)
{
    if(!root)return 0 ;
    if(left == false)
    {
        return 1 + helper(root->left , true) ;
    }
    
    return 1 + helper(root->right , false) ;
}

int Solution :: longestZigZag(TreeNode* root)
{
    if(!root)return 0 ;
    int ans1 = max(helper(root->left , true) , helper(root->right , false)) ;
    int ans2 = max(longestZigZag(root->left) , longestZigZag(root->right)) ;
    return max(ans1 , ans2) ;
}
