bool knows(int mat[MAX][MAX] , int celeb , int person)
{
    if(mat[celeb][person] == 1)
        return true ;
    return false ;
}
int getId(int mat[MAX][MAX], int n)
{
    int celeb = 0 ;
    for(int i = 1 ; i < n ; i++)
    {
        if(knows(mat , celeb , i))
        {
            celeb = i ;
        }
    }
    
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
