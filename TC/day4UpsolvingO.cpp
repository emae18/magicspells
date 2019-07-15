#include<bits/stdc++.h>
#define forin(i,n) for(int i=0;i<n;i++)
#define forisn(i,s,n) for(int i=s;i<n;i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
vector<vector<int>> g(64);
int a,b,c,d;

void add_edge(int i, int j) {
    if(i-2>=0 && j-1>=0) g[i*8+j].push_back(((i-2)*8)+(j-1));
    if(i-2>=0 && j+1<=7) g[i*8+j].push_back(((i-2)*8)+(j+1));
    if(i-1>=0 && j-2>=0) g[i*8+j].push_back(((i-1)*8)+(j-2));
    if(i+1<=7 && j-2>=0) g[i*8+j].push_back(((i+1)*8)+(j-2));
    if(i+2<=7 && j-1>=0) g[i*8+j].push_back(((i+2)*8)+(j-1));
    if(i+2<=7 && j+1<=7) g[i*8+j].push_back(((i+2)*8)+(j+1));
    if(i-1>=0 && j+2<=7) g[i*8+j].push_back(((i-1)*8)+(j+2));
    if(i+1<=7 && j+2<=7) g[i*8+j].push_back(((i+1)*8)+(j+2));
}

void t_graph() {
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            add_edge(i,j);
        }
     }
}

vector<int> bfs(vector<vector<int>>& g, int v) {
    vector<int> d(g.size(),-1);
    queue<int> q;
    d[v] = 0;
    q.push(v);
    while(!q.empty()) {
        int x=q.front();
        q.pop();
        for(int y: g[x]) {
            if(d[y] == -1) {
                d[y] = d[x] + 1;
                q.push(y);
            }
        }
    }
    return d;
}

int main() {
    t_graph();
    char x,y;
    while(cin>>x>>b>>y>>d)
    {
        if(b==-1)break;
        b--; d--;
        a = x-'0'-48-1; c = y-'0'-48-1;
        vector<int> r = bfs(g,(a*8)+b);
        cout<<"To get from "<<x<<b+1<<" to "<<y<<d+1<<" takes "<<r[c*8+d]<<" knight moves."<<"\n";
    }

    return 0;
}
