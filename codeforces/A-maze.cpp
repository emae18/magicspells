#include<bits/stdc++.h>
using namespace std;
map <int, vector<int> > g;
bool visited[250001];
bool marcado[250001];
int n,m,k,c;
char matriz[500][500];
map<int,pair<int,int> > pos;
vector<int> a;
void dfs(int x) {
    visited[x] = true;
    //int sum=1;
    a.push_back(x);
    for(int y: g[x])
        if(!visited[y]) //sum=sum+dfs(y);
            dfs(y);
    //if(c-sum <= k) matriz[pos[x].first][pos[x].second]='X';
    //return sum;
}
int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    cin>>n>>m>>k;
    int cont=0;
    int nodo;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>matriz[i][j];
            cont++;
            pos[cont]={i,j};
            if(matriz[i][j]=='.')
            {
                c++;
                if(j>0)
                {
                    if(i>0)
                    {
                        if(matriz[i-1][j]=='.')
                        {
                            g[cont].push_back(cont-m);
                            g[cont-m].push_back(cont);
                        }
                    }
                    if(matriz[i][j-1]=='.')
                        {
                            g[cont].push_back(cont-1);
                            g[cont-1].push_back(cont);
                        }
                }else {
                    if(matriz[i-1][j]=='.')
                        {
                            g[cont].push_back(cont-m);
                            g[cont-m].push_back(cont);
                        }
                }
            }
        }
    }
    //int vertexes = g.size();
    dfs(g.begin()->first);
    for(vector<int>::reverse_iterator it = a.rbegin();it!=a.rend() && k>0; it++)
    {
        matriz[pos[*it].first][pos[*it].second]='X';
        k--;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<matriz[i][j]<<"";
            cout<<"\n";
    }
    return 0;
}
