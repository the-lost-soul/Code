
/* The idea is to use level order traversal and maintain an invariant
 * that whenever we find a level with sum greater than previous level's
 * sum , then we update the overall sum
 */
int maxLevelSum(Node * root)
{
    // Keeps record of max. sum found till ith level .
    int overallSum = INT_MIN ;
    queue<Node *>q ;
    q.push(root) ;
    q.push(nullptr) ;
    int sum = 0 ;
    Node * node ;
    while(!q.empty())
    {
        node = q.front() ;
        sum += node->data ;
        q.pop() ;
        if(node->left) q.push(node->left) ;
        if(node->right) q.push(node->right) ;
        if(!q.front())
        {
            q.pop() ;
            // Update the overallSum after each level is completed .
            if(overallSum < sum) overallSum = sum ;
            sum = 0 ;
            // Checking this will help us in a way that we won't get
            // trapped in an infinite loop .
            if(q.empty()) break ;
            // push the marker for new level .
            else q.push(nullptr) ;
        }
        
    }
    return overallSum ;
}
