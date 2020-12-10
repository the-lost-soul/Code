void printBoundary(Node *root)
{
    if(!root)return ;
    
    vector<int>leftB ;
    leftB.push_back(root->data) ;
    
    Node* leftTraverse = root->left ;
    // store the left boundary except the leaf node .
    while(leftTraverse)
    {
        if(!leftTraverse->left and !leftTraverse->right)break ;
        leftB.push_back(leftTraverse->data) ;
        if(leftTraverse->left)leftTraverse = leftTraverse->left ;
        else if(leftTraverse->right)leftTraverse = leftTraverse->right ;
        
    }
    
    // store all the leaf nodes from left to right .
    queue<Node*>q ;
    q.push(root) ;
    while(!q.empty())
    {
        Node* temp = q.front() ;
        q.pop() ;
        if(!temp->left and !temp->right)leftB.push_back(temp->data) ;
        if(temp->left)q.push(temp->left) ;
        if(temp->right)q.push(temp->right) ;
    }
    
    // Store the right boundary
    vector<int>rightB ;
    Node* rightTraverse = root->right ;
    while(rightTraverse)
    {
        if(!rightTraverse->left and !rightTraverse->right)break ;
        rightB.push_back(rightTraverse->data) ;
        if(rightTraverse->left)rightTraverse = rightTraverse->left ;
        else if(rightTraverse->right)rightTraverse = rightTraverse->right ;
    }
    // reverse the result to get thr orientation of right boundary
    // from left to right .
    reverse(rightB.begin() , rightB.end()) ;
    
    // Print the result .
    for(int i = 0 ; i < leftB.size() ; i++)cout << leftB[i] <<" " ;
    for(int i = 0 ; i < rightB.size() ; i++)cout << rightB[i] <<" " ;
    
    
}
