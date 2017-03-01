#include<iostream>
using namespace std;
int main(void)
{
    int m,n,i;
    cin>>m>>n;
    int s=0,l=0;

    while(s<m && l<n)
    {
        for(i=l;i<n;i++)
        {
            cout<<a[s][i];
        }
        s++;

        for(i=s;i<m;i++)
        {
            cout<<a[i][n-1];
        }
        n--;

        if(s < m)
        {
            for(i = n-1;i>= l; --i)
            {
                cout<<a[m-1][i];
            }
            m--;
        }

        if( l < n )
        {
            for(i = n-1) // Pending
        }
    }
}
