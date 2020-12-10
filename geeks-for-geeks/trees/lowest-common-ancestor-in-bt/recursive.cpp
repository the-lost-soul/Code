void findNode(Node *root, int num, bool &find)
{
    // If tree doesn't exist then return NULL.
    if(root==NULL)return ;
    
    // If tree exists,then check if curent node
    // is equal to the number to be found or not.
    // If yes then set the find to be true.
    if(root->data==num)
    {
        find=true;
        exit;
    }
    
    // Do an inorder traversal of the tree.
    findNode(root->left,num,find);
    findNode(root->right,num,find);
    
}
Node *findLCA(Node *root, int n1, int n2, bool &find1, bool &find2)
{
    // If tree doesn't exist then return NULL.
    if(root==NULL)return NULL;
    
    // If the current root is equal to n1,
    // then set find1=true and return root.
    if(root->data==n1)
    {
        find1=true;
        return root;
    }
    
    // If the current root is equal to n2,
    // then set find2=true and return root.
    // If we reach here,then this also means
    // that the node with value n1 is not
    // present in this sub-tree.
    if(root->data==n2)
    {
        find2=true;
        return root;
    }
    
    // Traverse the left sub-tree for finding the LCA.
    Node *left=findLCA(root->left,n1,n2,find1,find2);
    
    // Traverse the right sub-tree for finding the LCA.
    Node *right=findLCA(root->right,n1,n2,find1,find2);
    
    // If both left LCA and right LCA is not NULL,then
    // return the current root as LCA.
    if(left && right)return root;
    
    // If any one is NULL then that means the number
    // searched is not present in that sub-tree so
    // return the LCA which is not NULL.
    if(left!=NULL && right==NULL)return left;
    else if(left==NULL && right!=NULL)return right;
    
}
Node *LCA(Node* root ,int n1 ,int n2 )
{
    // Tells which variable is present in tree.
    bool find1=false;
    bool find2=false;
    
    // Utility function to find LCA of two numbers.
    Node *answer=findLCA(root,n1,n2,find1,find2);
    
    // If both find1 and find2 is true then return
    // the LCA i.e answer.
    if(find1 && find2)return answer;
    
    // If not then two case arises.
    else
    {
        // 1.)If first number was not found during
        // traversal of tree while finding LCA.
        if(!find1)
        {
            findNode(root->left,n1,find1);
            findNode(root->right,n1,find1);
        }
        
        // 2.)If second number was not found during
        // traversal of tree while finding LCA.
        if(!find2)
        {
            findNode(root->left,n2,find2);
            findNode(root->right,n2,find2);
        }
    }
    
    // If both numbers are present in tree,then
    // simply return the LCA.
    if(find1 && find2)return answer;
    
    // If not,then return NULL.
    else return NULL;
    
}


