#include<bits/stdc++.h>
#define forin(i,n) for(int i=0;i<n;i++)
#define forisn(i,s,n) for(int i=s;i<n;i++)
#define mostrar(x,v) for(auto x: v)cout<<x<<" ";
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vl v(n);
    forin(i,n)
        cin>>v[i];
    int sum=n;
    for(int i=0;i<v.size();i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            if(v[j]%(i+1)==0)sum++;
            else {v.erase(v.begin()+j-1);i--;}
            mostrar(x,v);
            cout<<"\n";
        }
    }
    cout<<sum<<"\n";
    return 0;
}
