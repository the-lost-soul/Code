bool knows(int mat[MAX][MAX] , int celeb , int person)
{
    if(mat[celeb][person] == 1)
        return true ;
    return false ;
}
int getId(int mat[MAX][MAX], int n)
{
    int low = 0 , high = n - 1 ;
    // It will terminate when low == high , hence finally
    // there is a chance that celebrity can be low == high .
    while(low < high)
    {
        if(knows(mat , low , high))
        {
            low++ ;
        }
        else high-- ;
    }
    int celeb = low ;
    for(int i = 0 ; i < n ; i++)
    {
        if(i != celeb)
        {
            if(knows(mat , celeb , i) or !knows(mat , i , celeb))
            {
                return -1 ;
            }
        }
    }
    return celeb ;
}
