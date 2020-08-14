/*To find the largest sum in contiguous subarray*/
#include<bits/stdc++.h>
using namespace std;

int kadane(int *a,int n)
{
    int currHigh=a[0],globHigh=a[0];
    for(int i=1 ; i<n ; i++)
    {
        currHigh=max(a[i],currHigh+a[i]);
        if(currHigh>globHigh)
            globHigh=currHigh;
    }
    return globHigh;
}
int main()
{
    int t,n,i,sum;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int *a=new int[n];
        for(i=0 ; i<n ; i++)
            cin>>a[i];
        sum=kadane(a,n);
        cout<<sum<<endl;
    }
    return 0;
}
