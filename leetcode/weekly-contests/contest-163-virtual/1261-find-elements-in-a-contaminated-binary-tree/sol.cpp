/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements 
{
    TreeNode* root ;
    bool treeRoot = true ;
    public:
        FindElements(TreeNode* root , int val = 0) 
        {
            if(treeRoot == true)
            {
                this->root = root ;
                treeRoot = false ;
            }
            if(!root)return ;
            root->val = val ;
            FindElements(root->left , 2*val + 1) ;
            FindElements(root->right , 2*val + 2) ;
        }

        bool find(int target) 
        {
            if(!root)return false ;
            if(root->val == target)
            {
                return true ;
            }
            stack<TreeNode*>myStack ;
            myStack.push(root) ;
            while(!myStack.empty())
            {
                TreeNode* currNode = myStack.top() ;
                if(currNode->val == target)return true ;
                myStack.pop() ;
                if(currNode->right != nullptr)
                    myStack.push(currNode->right) ;
                if(currNode->left != nullptr)
                    myStack.push(currNode->left) ;
            }
            return false ;
        }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
