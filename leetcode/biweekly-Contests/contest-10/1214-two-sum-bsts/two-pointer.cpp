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
    void inOrder(TreeNode* root1 , vector<int>&inOrder1) ;
};

void Solution :: inOrder(TreeNode* root , vector<int>&inorder)
{
    if(!root)return ;
    inOrder(root->left , inorder) ;
    inorder.push_back(root->val) ;
    inOrder(root->right , inorder) ;
}
bool Solution :: twoSumBSTs(TreeNode* root1, TreeNode* root2, int target)
{
    // Get the inorder traversal of both BST's to get a sorted vector .
    vector<int>inOrder1 ;
    inOrder(root1 , inOrder1) ;
    vector<int>inOrder2 ;
    inOrder(root2 , inOrder2) ;
    
    int len1 = inOrder1.size() , len2 = inOrder2.size() , i = 0 , j = len2 - 1 ;
    vector<int>ans ;
    // Using two pointer technique , set i = 0 for tree1 and j = len2 - 1
    // for tree2 .
    while(i < len1 and j >= 0)
    {
        // If we get the desired element , then return true .
        if(inOrder1[i] + inOrder2[j] == target)return true ;
        // If the sum of current element is greater than target , then
        // move forward in tree1 to get a larger element .
        else if(inOrder1[i] + inOrder2[j] < target)i++ ;
        else j-- ;
    }
    return false ;
}
