class RandomizedSet 
{
    
public:
    unordered_map<int , int>hash ;
    vector<int>myVector ;
    /** Initialize your data structure here. */
    RandomizedSet() 
    {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) 
    {
        if(hash.find(val) != hash.end())
            return false ;
        myVector.push_back(val) ;
        hash[val] = myVector.size() - 1 ;
        return true ;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) 
    {
        if(hash.find(val) == hash.end())
            return false ;
        int valPos = hash[val] ;
        myVector[valPos] = myVector[myVector.size() - 1] ;
        hash[myVector[valPos]] = valPos ;
        myVector.pop_back() ;
        hash.erase(val) ;
        return true ;
    }
    
    /** Get a random element from the set. */
    int getRandom() 
    {
        int len = myVector.size() ;
        return myVector[rand()%len] ;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
