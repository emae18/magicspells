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
    int n,k;
    cin>>n>>k;
    vi v(n);
    forin(i,n)cin>>v[i];
    vi copi(v.begin(),v.end());
    sort(all(v));
    int may1= v[n-1]/k;
    int min1=v[0]/k;
    //if(v[n-1]%k>0)may++;
    int may2 =v[n-1]/k+(v[n-1]%k);
    int min2 =v[0]/k+(v[0]%k);
    //cout<<"min1-> "<<min1<<"\n may1-> "<<may1<<"\n";
    //cout<<"min2-> "<<min2<<"\n may2-> "<<may2<<"\n";
    //if(v[0]%k>0)mi++;
    if(abs(may1-min1)<=1 && abs(may2-min2)<=1 ){
        cout<<"YES\n";
        forin(i,n)
        {
            forisn(l,1,copi[i]+1)
            {
                cout<<l%k+1<<" ";
            }
            cout<<"\n";
        }
        return 0;
    }
    cout<<"NO\n";
    return 0;
}
