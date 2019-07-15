#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > g(65);
int d=0;
vector<int > bfs(int nodo)
{
    vector<int> d(g.size(),-1);
    queue<int> q;
    d[nodo]=0;
    q.push(nodo);
    while(!q.empty())
    {
        int x= q.front();
        q.pop();
        for(int y : g[x])
        {
            if(d[y]==-1)
            {
                d[y]=d[x]+1;
                q.push(y);
            }
        }
    }
    return d;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=1;i<=64;i++)
    {
        if(i+6>0 && i!=1 && i!=64 && i!=56 && i!=2 && i!=9)g[i].push_back(i+6);
        if(i+10>0 && i!=8 && i!=64 && i!=56 && i!=7 && i!=16)g[i].push_back(i+10);
        if(i+17>0 && i!=8 && i!=64 && i!=56 && i!=16)   g[i].push_back(i+17);
        if(i+15>0 && i!=1 && i!=64 && i!=56 && i!=9)        g[i].push_back(i+15);
        if(i-6 >0 && i!=8 && i!=1 && i!=64 && i!=16 && i!=7)        g[i].push_back(i-6);
        if(i-10>0 && i!=8 && i!=1 && i!=56 )        g[i].push_back(i-10);
        if(i-15> 0 && i!=8 && i!=1 && i!=64)        g[i].push_back(i-15);
        if(i-17>0 && i!=1 && i!=8 && i!=56)        g[i].push_back(i-17);

    }
    for(int i=1;i<g.size();i++)
    {
        cout<<i<<"->";
        for(int j=0;j<g[i].size();j++)
        {
            cout<<g[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
