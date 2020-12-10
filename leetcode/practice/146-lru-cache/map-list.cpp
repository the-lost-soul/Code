class Node
{
    public :
    int key ;
    int value ;
    Node(int key , int value)
    {
        this->key = key ;
        this->value = value ;
    }
} ;

class LRUCache 
{
    int capacity ;
    unordered_map<int , list<Node> :: iterator>hash ;
    list<Node>cache ;
public:
    LRUCache(int capacity) 
    {
        this->capacity = capacity ;
    }
    
    int get(int key) 
    {
        if(hash.find(key) == hash.end()) 
            return -1 ;
        
        auto itr = hash[key] ;
        int value = (*itr) .value ;
        hash.erase(key) ;
        cache.erase(itr) ;
        put(key , value) ;
        return value ;
    }
    
    void put(int key, int value) 
    {
        // If key is already present in cache .
        if(hash.find(key) != hash.end())
        {
            auto itr = hash[key] ;
            hash.erase(key) ;
            cache.erase(itr) ;
        }
        
        // If cache capacity is full .
        if(cache.size() == capacity)
        {
            int LRUKey = cache.back().key ;
            cache.pop_back() ;
            hash.erase(LRUKey) ;
        }
        
        cache.push_front(Node(key , value)) ;
        auto itr = cache.begin() ;
        hash[key] = itr ; 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
