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
    void solve(TreeNode* root , int num , int& sum)
    {
        if(!root)
            return ;
        if(!root->left and !root->right)
        {
            sum += (num*10 + root->val) ;
            return ;
        }

        solve(root->left , num*10 + root->val , sum) ;
        solve(root->right , num*10 + root->val , sum) ;
    }
    int sumNumbers(TreeNode* root)
    {
        int sum = 0 ;
        solve(root , 0 , sum) ;
        return sum ;
    }
};
