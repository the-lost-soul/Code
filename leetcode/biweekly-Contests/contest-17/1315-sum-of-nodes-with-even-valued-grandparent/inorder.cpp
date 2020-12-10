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
    int sumEvenGrandparent(TreeNode* root , int parent , int grandParent) ;
};

int Solution :: sumEvenGrandparent(TreeNode* root , int parent = 1 , int grandParent = 1)
{
    if(!root)
        return 0 ;
    int sum = 0 ;
    if(grandParent%2 == 0)
        sum += root->val ;
    sum += sumEvenGrandparent(root->left , root->val , parent) ;
    sum += sumEvenGrandparent(root->right , root->val , parent) ;
    return sum ;
}
