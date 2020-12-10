// Approach - 1-- single traversal of original linked list but code is a
                  Little messy. 

      
// Should return the head of the copied linked list the
//output will be 1 if successfully copied
Node * copyList(Node * origHead)
{
    unordered_map<Node * , Node *>hash ;
    Node *cloneHead = nullptr ;
    Node * clonePrev = nullptr ;
    
    while(origHead)
    {
        Node *cloneNode = new Node ;
        
        // Copy the original data of a node to it's respective cloned list .
        cloneNode->data = origHead->data ;
        
        // Hash this present node and original node
        
        /* The reason why we are doing this is because after traversing some
         * nodes,we may get a node whose let's say "Node-x" arbitrary pointer
         * points to the present head and since we have already cloned the current
         * node , so we can use the already cloned node for initialising "node-x"
         * arbitrary location , instead of allocating new memeory for the already
         * cloned node .
         */
        hash[origHead] = cloneNode ;
        
        // Connect the last node if exists with present node of cloned LL .
        if(clonePrev)
        {
            clonePrev->next = cloneNode ;
            clonePrev = cloneNode ;
        }
        
        // Connect the first node to cloneHead
        if(!cloneHead)
        {
            cloneHead = cloneNode ;
            clonePrev = cloneNode ;
        }
        
        // If present node's arbitrary points to some other node , then -->
        if(origHead->arb)
        {
            
            // Find whether we have already cloned this node or not .
            // If not , then -->
            if(hash.find(origHead->arb) == hash.end())
            {
                // Allocate memory for the arbitrary node .
                Node * random = new Node ;
                random->data = origHead->arb->data ;
                cloneNode->arb = random ;
                
                // Hash this arbitrary node .
                hash[origHead->arb] = random ;
            }
            else
            {
                cloneNode->arb = hash[origHead->arb] ;
            }
        }
        else cloneNode->arb = nullptr ;
        
        // Traverse ahead in original linked list .
        origHead = origHead->next ;
        
        // Alloacte lsat node's next memory address to "NULL" .
        if(!origHead)cloneNode->next = nullptr ;
    }
    
    
    return cloneHead ;
    
}
