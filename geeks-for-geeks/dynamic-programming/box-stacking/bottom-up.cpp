typedef struct box
{
    int h , w , l ;
}box ;

bool comp(const box a , const box b)
{
    return (a.w*a.l) > (b.w*b.l) ;
}

/*The function takes an array of heights, width and 
length as its 3 arguments where each index i value 
determines the height, width, length of the ith box. 
Here n is the total no of boxes.*/
int maxHeight(int height[],int width[],int length[],int n)
{
    box rotation[6*n] ;
    int index = 0 ;
    for(int i = 0 ; i < n ; i++)
    {
        rotation[index++] = {height[i] , width[i] , length[i]} ;
        rotation[index++] = {height[i] , length[i] , width[i]} ;
        rotation[index++] = {width[i] , height[i] , length[i]} ;
        rotation[index++] = {width[i] , length[i] , height[i]} ;
        rotation[index++] = {length[i] , width[i] , height[i]} ;
        rotation[index++] = {length[i] , height[i] , width[i]} ;
    }
    
    n = 6*n ;
    sort(rotation , rotation + n , comp) ;
    vector<int>dp(n , 0) ;
    for(int i = 0 ; i < n ; i++)dp[i] = rotation[i].h ;
    for(int i = 1 ; i < n ; i++)
    {
        for(int j = 0 ; j < i ; j++)
        {
            if(rotation[i].w < rotation[j].w and rotation[i].l < rotation[j].l)
            {
                dp[i] = max(dp[i] , dp[j] + rotation[i].h) ;
            }
        }
    }
    return *max_element(dp.begin() , dp.end()) ;
}
