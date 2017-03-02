#include<iostream>
using namespace std;
int main(void)
{
    int m,n,i,j,k;
    cin>>m>>n;
    int s=0,l=0;
    int b[10][10];
    int a[10][10];
    for(j=0;j<m;j++)
    {
        for(k =0;k<n;k++)
        {
            cin>>b[j][k];
        }
        cout<<"\n";
    }
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
            for(i = m-1; i>=k; --i)
            {
                cout<<a[i][l];// Pending
            }
            l++;
    }
}
}
