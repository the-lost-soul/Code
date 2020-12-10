
/* The idea is to use level order traversal and maintain an invariant
 * that whenever we find a level with width greater than previous level's
 * width , then we update the overall Width .
 */
int getMaxWidth(Node* root)
{
   // Keeps record of max. width found till ith level .
    int overallWidth = INT_MIN ;
    queue<Node *>q ;
    q.push(root) ;
    q.push(nullptr) ;
    int width = 0 ;
    Node * node ;
    while(!q.empty())
    {
        node = q.front() ;
        width ++ ;
        q.pop() ;
        if(node->left) q.push(node->left) ;
        if(node->right) q.push(node->right) ;
        if(!q.front())
        {
            q.pop() ;
            // Update the overallWidth after each level is completed .
            if(overallWidth < width) overallWidth = width ;
            width = 0 ;
            // Checking this will help us in a way that we won't get
            // trapped in an infinite loop .
            if(q.empty()) break ;
            // push the marker for new level .
            else q.push(nullptr) ;
        }
        
    }
    return overallWidth ;
}
