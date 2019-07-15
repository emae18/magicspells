#include<bits/stdc++.h>
#define forin(i,n) for(int i=0;i<n;i++)
#define forisn(i,s,n) for(int i=s;i<n;i++)
#define mostrar(x,v) for(auto x: v)cout<<x<<" ";
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
map<int,int> mapa;

int n,k,a;

set<int> disp;

int cuanto(int l,int r)
{
    int ans=(abs(r-l)+2)/(a+1);
    return ans;
}
bool check(int i)
{
    disp.insert(i);
    int c=0;
    int aux;
    set<int>::iterator it=disp.begin();
    while(it!=disp.end())
    {
       // cout<<"i set-> "<<*it<<" ";
        aux=*it;
        it++;
        if(it==disp.end())break;
        //cout<<"i+1 set-> "<<*it<<" ";
        c+=cuanto(aux,*it);
    }
    //cout<<"\nc-> "<<c<<"\n";
    return c==k;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k>>a;
    int m;
    cin>>m;
    int l=0;
    disp.insert(1);
    disp.insert(n);
    vi plays(m);
    forin(i,m)
        cin>>plays[i];
        int z=-1;
    for(int i=0;i<m;i++)
    {
        if(!check(plays[i])){z=i+1;;break;}
    }
    cout<<z<<"\n";
    return 0;
}
