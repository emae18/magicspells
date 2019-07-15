#include<bits/stdc++.h>
#define forin(i,n) for(int i=0;i<n;i++)
#define forisn(i,s,n) for(int i=s;i<n;i++)
#define mostrar(x,v) for(auto x: v)cout<<x<<" ";
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
vector<vector<ll> > g;
vector<ll> colores(10000,-1);
int c=0;
bool bfs(int v) {
    queue<int> q;
    q.push(v);
    colores[v]=0;
    while(!q.empty()) {
        int x=q.front();
        q.pop();
        for(int y: g[x]) {
            if(colores[y]!=-1){
                if(colores[x]==colores[y])
                    return false;
            }else{
                q.push(y);
                colores[y]=1-colores[x];
                //cout<<"x> "<<x<<"\n y>"<<y<<"\n";
            }
        }
    }
    return true;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    forin(i,t)
    {
        int n,s;
        cin>>n>>s;
        ll nodo,vec;
        g.resize(n+1);
        fill(all(g),vector<ll>());
        while(s--)
        {
            cin>>nodo>>vec;
            g[nodo].push_back(vec);
            g[vec].push_back(nodo);
        }
        bool bipart=true;
        for(int z=1;z<n+1;z++)
        {
            if(colores[z]==-1)
                bipart=bipart &&bfs(z);
        }
        if(bipart)
            cout<<"Scenario #"<<i+1<<":\nNo suspicious bugs found!\n";
        else
            cout<<"Scenario #"<<i+1<<":\nSuspicious bugs found!\n";

        fill(all(colores),-1);

    }
    return 0;
}
