const ll N=10;
ll arr[N];
ll sz[N];

void initialize()
{
    for(ll i=0 ; i<N ; i++)
    {
        arr[i]=i;
        sz[i]=1;
    }
}

ll root(ll x)
{
    if(x!=arr[x]) 
    {
        arr[x]=root(arr[x]);
    }
    return arr[x];
}

bool findab(ll a,ll b)
{
    if(root(a)==root(b))
        return true;
    return false;
}
void unionab(ll a, ll b)
{
    if(root(a)==root(b))
        return;

    ll ra=root(a);
    ll rb=root(b);
    if(sz[ra]<sz[rb])
    {
        arr[ra]=arr[rb];
        sz[rb]+=sz[ra];
    }
    else
    {
        arr[rb]=arr[ra];
        sz[ra]+=sz[rb];
    }
}
