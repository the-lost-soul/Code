class Cashier 
{
    int n , discount , customerCount ;
    unordered_map<int , int>hash ;
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) 
    {
        customerCount = 0 ;
        this->n = n ;
        this->discount = discount ;
        for(int i = 0 ; i < products.size() ; i++)
        {
            hash[products[i]] = prices[i] ;
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) 
    {
        customerCount++ ;
        int len = product.size() ;
        double bill = 0.0 ;
        for(int i = 0 ; i < len ; i++)
        {
            bill += amount[i]*hash[product[i]] ;
        }
        
        if(customerCount == n)
        {
            bill = bill - bill*(discount/100.0) ;
            customerCount = 0 ;
        }
        
        return bill ;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
