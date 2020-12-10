void topView(struct Node *root)
{
    unordered_map<int , int>hash ;
    queue<pair<Node* , int>>myQueue ;
    myQueue.push({root , 0}) ;
    int left = 0 , right = 0 ;
    while(!myQueue.empty())
    {
        auto details = myQueue.front() ;
        myQueue.pop() ;
        Node* node = details.first ;
        int depth = details.second ;
        if(hash.find(depth) == hash.end())
        {
            hash[depth] = node->data ;
        }
        if(node->left)
        {
            myQueue.push({node->left , depth - 1}) ;
            left = min(left , depth - 1) ;
            
        }
        
        if(node->right)
        {
            myQueue.push({node->right , depth + 1}) ;
            right = max(right , depth + 1) ;
        }
        
    }
    
    for(int i = left ; i <= right ; i++)
    {
        cout << hash[i] << " " ;
    }
}


