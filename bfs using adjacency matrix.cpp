#include<bits/stdc++.h>
using namespace std;

bool visited[8];

void initialize()
{
    for(int i=0 ; i<8 ; i++)
    visited[i]=false;
}

void printAdj_Mat(int adj[][8])
{
    for(int i=0 ; i<8 ; i++)
    {
        for(int j=0 ; j<8 ; j++)
        cout<<adj[i][j]<<' ';
        cout<<endl;
    }
}
void bfs(int adj[][8],int s)
{
    initialize();
    queue<int> q;
    q.push(s);
    visited[s]=true;

    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        for(int i=0 ; i<8 ; i++)
        {
            if(adj[temp][i]==1)
            {
                if(!visited[i])
                {
                    q.push(i);
                    cout<<i<<' ';
                    visited[i]=true;
                }
            }
        }
    }
}
int main()
{
cout<<"               GRAPH";
cout<<"\n                 0";
cout<<"\n               / | \\";
cout<<"\n              /  |  \\";
cout<<"\n             /   |   \\";
cout<<"\n            /    |    \\";
cout<<"\n           1      2    3";
cout<<"\n          / \\    / \\  /";
cout<<"\n         /   \\  /   \\/";
cout<<"\n        4     5 6    7";

    int adj_undir[8][8]={
                           0,1,1,1,0,0,0,0,
                           1,0,0,0,1,1,0,0,
                           1,0,0,0,0,0,1,1,
                           1,0,0,0,0,0,0,1,
                           0,1,0,0,0,0,0,0,
                           0,1,0,0,0,0,0,0,
                           0,0,1,0,0,0,0,0,
                           0,0,1,1,0,0,0,0
                        };
    int adj_dir[8][8]={
                           0,1,1,1,0,0,0,0,
                           0,0,0,0,1,1,0,0,
                           0,0,0,0,0,0,1,1,
                           0,0,0,0,0,0,0,1,
                           0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0
                        };

    int s;
    cout<<"\n\nEnter source node : ";
    cin>>s;
    if(s>7)
    {
        cout<<"Invalid source node !";
        return 0;
    }
    cout<<"\nUndirected Graph"<<endl;
    cout<<"Traversal order : ";bfs(adj_undir,s);
    cout<<"\n\nDirected Graph(top to bottom)"<<endl;
    cout<<"Traversal order : ";bfs(adj_dir,s);

    return 0;
}
