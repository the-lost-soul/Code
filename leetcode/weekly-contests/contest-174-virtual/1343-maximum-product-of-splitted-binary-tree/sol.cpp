/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    int maxProduct(TreeNode* root) ;
    void changeTree(TreeNode* root) ;
};

void Solution :: changeTree(TreeNode* root)
{
    if(!root)return ;
    
    changeTree(root->left) ;
    changeTree(root->right) ;
    
    if(root->left)
        root->val += (root->left)->val ;
    if(root->right)
        root->val += (root->right)->val ;
}

int Solution :: maxProduct(TreeNode* root)
{
    changeTree(root) ;
    stack<TreeNode*>myStack ;
    myStack.push(root) ;
    int rootVal = root->val ;
    long ans = INT_MIN , modulo = 1e9 + 7 ;
    while(!myStack.empty())
    {
        TreeNode* currNode = myStack.top() ;
        myStack.pop() ;
        // tree1-->denotes right and tree2-->denotes left
        long tree1 , tree2 , ansLeft , ansRight ;
        tree1 = tree2 = ansLeft = ansRight = INT_MIN ;
        if(currNode->left)
        {
            tree1 = abs(currNode->val - currNode->left->val) ;
            ansLeft = tree1*(currNode->left->val) ;
            currNode->left->val = rootVal ;
            myStack.push(currNode->left) ;
            
        }
        if(currNode->right)
        {
            tree2 = abs(currNode->val - currNode->right->val) ;
            ansRight = tree2*(currNode->right->val) ;
            currNode->right->val = rootVal ;
            myStack.push(currNode->right) ;   
        }
        ans = max(ans , max(ansLeft , ansRight)) ;
    }
    
    return ans%modulo ;
}
