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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) ;
    bool search(TreeNode* root2 , int desiredNum) ;
};

bool Solution :: search(TreeNode* root2 , int desiredNum)
{
    if(root2 == NULL)return false ;
    if(desiredNum == root2->val)return true ;
    
    if(desiredNum > root2->val)return search(root2->right , desiredNum) ;
    return search(root2->left , desiredNum) ;
}
bool Solution :: twoSumBSTs(TreeNode* root1, TreeNode* root2, int target)
{
    if(!root1 or !root2)return false ;
    bool ans = search(root2 , target - root1->val) ;
    return ans or twoSumBSTs(root1->right , root2 , target) or twoSumBSTs(root1->left , root2 , target) ;
}
