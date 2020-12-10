void helper(Node * root , unordered_map<int , int>&umap
            , int &distLeft , int &distRight , int current)
{
    if(!root)return ;
    if(current > distRight)distRight = current ;
    if(current < distLeft)distLeft = current ;
    helper(root->left , umap , distLeft , distRight , current - 1) ;
    helper(root->right , umap , distLeft , distRight , current + 1) ;
}
void print(unordered_map<int , int>&umap , int distLeft , int distRight)
{
    for(int i = distLeft ; i <= distRight ; i++)
    {
        cout<<umap[i]<<" " ;
    }
}
// Method that prints the bottom view.
void bottomView(Node *root)
{
    unordered_map<int , int>umap ;
    int distLeft = 0 ;
    int distRight = 0 ;
    int current = 0 ;
    helper(root , umap , distLeft , distRight , current) ;
    print(umap , distLeft , distRight) ;
}
