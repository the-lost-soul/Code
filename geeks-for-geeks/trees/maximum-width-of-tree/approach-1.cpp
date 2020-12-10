
int getHeight(Node * root)
{
    if(!root)return 0 ;
    
    return 1 + max(getHeight(root->left) , getHeight(root->right)) ;
}

int getWidth(Node * root , int level)
{
    if(!root)return 0 ;
    if(level == 1)return 1 ;
    else return getWidth(root->left , level - 1) + getWidth(root->right , level - 1) ;
}

int getMaxWidth(Node* root)
{
    int height = getHeight(root) ;
    int width = 0 ;
    int level = 1 ;
    while(level <= height)
    {
        width = max(width , getWidth(root , level)) ;
        level ++ ;
    }
    return width ;
}
