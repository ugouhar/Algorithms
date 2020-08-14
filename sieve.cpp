#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

bool prime[MAX];

void initialize()
{
    for(int i=0 ; i<MAX ; i++)
        prime[i]=true;
}

int main()
{

    initialize();
    prime[0]=false;
    prime[1]=false;
    for(int i=2 ; i*i<MAX ; i++)
    {
        if(prime[i])
        {
            for(int j=i*i ; j<MAX ; j+=i)
            prime[j]=false;
        }
    }
    for(int i=0 ; i<MAX ; i++)
        if(prime[i])
            cout<<i<<' ';
}
