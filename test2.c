int MaxSum2(int *A, int n)
{
    int nStart = A[n-1];
    int nAll = A[n-1];    
    for(int i = n-2;i>=0;--i)
    {
        if(nStart<0)
            nStart = 0;
        nStart += A[i];
        if(nStart>=nAll)
        {
            nAll = nStart;           
        }
    }
    return nAll;
}
