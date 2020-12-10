
int print(Node * root , int count , bool &flag)
{
    if(!root)return 0 ;
    
    if(!root->left and !root->right)
    return 1 ;
    
    int total = print(root->left , count , flag) + 
                print(root->right , count , flag) ;
    
    if(total == count)
    {
        cout<<root->data<<" " ;
        flag = true ;
    }
    
    return total ;
}
/*You are required to complete below method */
void btWithKleaves(Node *root, int count)
{ 
    bool flag = false ;
    int total = print(root , count , flag) ;
    if(!flag)cout<<"-1 " ;
    cout<<endl ;
}
