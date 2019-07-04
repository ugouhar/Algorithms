/*
    Root = Index 0
    Implementation of binary tree to 
    find index of left child, right child
    and total number of childs of any node;
*/

#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define pll pair<ll,ll>
#define pb push_back
#define MAX 105
using namespace std;
 

ll lchild[MAX], rchild[MAX], nchild[MAX];
void init()
{
    for(ll i=0 ; i<MAX ; i++)
    {
        lchild[i]=-1;
        rchild[i]=-1;
        nchild[i]=0;
    }
}

void dfs(ll s)
{
    if(lchild[s]!=-1)
    {
        dfs(lchild[s]);
        nchild[s]+=1+nchild[lchild[s]];
    } 


    if(rchild[s]!=-1)
    {
        dfs(rchild[s]);
        nchild[s]+=1+nchild[rchild[s]];
    }
}


void solve()
{

    init();
    ll n;
    cin>>n;
    ll a[n];

    for(ll i=0 ; i<n ; i++)
    {
        cin>>a[i];
    }
    ll root=a[0];


    for(ll i=1 ; i<n ; i++)
    {
        ll j=0;
        while(true)
        {
            if(a[i]>=a[j])
            {
                if(rchild[j]==-1)
                {
                    rchild[j]=i;
                    break;
                }
                j=rchild[j];
            }
            else
            {
                if(lchild[j]==-1)
                {
                    lchild[j]=i;
                    break;
                }
                j=lchild[j];
            }
        }
    }
    dfs(0);

    for(ll i=0 ; i<n ; i++)
    {
        cout<<i<<' ';
        cout<<lchild[i]<<' ';
        cout<<rchild[i]<<' ';
        cout<<nchild[i]<<' ';
        cout<<endl;
    }
}




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
 
    freopen("input.txt","r",stdin);
        

    solve();
 
    return 0;
    //Always comment out input.txt and output.txt
}