#include<iostream>
using namespace std;

int* fib_dyn(int n)
{
    int i;
    int *f = (int*)malloc((n+1)*sizeof(int));
    for(i = 0 ; i <= n;i++)
    {
        if(i<=1)
        {
            f[i]=i;
        }
        else
        {
            f[i]=f[i-1]+f[i-2];
        }
    }
    return f;
}

int main()
{
    int n=9;
    int* result = fib_dyn(n);
    for(int i = 0 ; i<n;i++)
    {
        cout<<result[i]<<" ";
    }
}
