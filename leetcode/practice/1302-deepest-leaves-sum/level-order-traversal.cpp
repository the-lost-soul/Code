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
    int deepestLeavesSum(TreeNode* root) ;
};

int Solution :: deepestLeavesSum(TreeNode* root)
{
    queue<TreeNode*>myQueue ;
    myQueue.push(root) ;
    TreeNode* temp = NULL ;
    myQueue.push(temp) ;
    int sum = 0 ;
    while(!myQueue.empty())
    {
        TreeNode* node = myQueue.front() ;
        sum += node->val ;
        myQueue.pop() ;
        if(node->left)myQueue.push(node->left) ;
        if(node->right)myQueue.push(node->right) ;
        if(myQueue.front() == nullptr)
        {
            myQueue.pop() ;
            if(myQueue.empty())
            {
                break ;
            }
            sum = 0 ;
            myQueue.push(temp) ; 
        }
    }
    return sum ;
}
