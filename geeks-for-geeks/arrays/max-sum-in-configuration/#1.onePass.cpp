int findExtra(int a[],int b[],int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] != b[i])return i ;
    }
    return n ;
}
