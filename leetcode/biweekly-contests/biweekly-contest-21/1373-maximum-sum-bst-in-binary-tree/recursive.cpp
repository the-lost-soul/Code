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
    int ans = 0 ;
    int maxSumBST(TreeNode* root) ;
    pair<bool , int> helper(TreeNode* root) ;
};

pair<bool , int> Solution :: helper(TreeNode* root)
{
    if(!root)return {true , 0} ;
    
    pair<bool , int>left = helper(root->left) ;
    pair<bool , int>right = helper(root->right) ;
    
    if(root->left and root->left->val >= root->val)
        return {false , INT_MIN} ;
    if(root->right and root->right->val <= root->val)
        return {false , INT_MIN} ;
    
    if(root->left and root->left->right and root->left->right->val >= root->val)
        return {false , INT_MIN} ;
    
    if(root->right and root->right->left and root->right->left->val <= root->val)
        return {false , INT_MIN} ;

    if(left.first and right.first)
    {
        int sum = root->val + left.second + right.second ;
        ans = max(ans , sum) ;
        return {true , sum} ;
    }
    return {false , INT_MIN} ;
}

int Solution :: maxSumBST(TreeNode* root)
{
    helper(root) ;
    return ans ;
}
