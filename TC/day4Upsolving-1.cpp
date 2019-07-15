#include<bits/stdc++.h>
#define forin(i,n) for(int i=0;i<n;i++)
#define forisn(i,s,n) for(int i=s;i<n;i++)
#define mostrar(x,s) for(auto x : s)cout<<x<<" ";
#define all(v) v.begin(),v.end()

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int w,g,n;
        cin>>w>>g>>n;
        vector<pair<int,int> > v(n);
        forin(i,n)
            cin>>v[i].first>>v[i].second;
        vector<pair<int,int> > points(v.begin(),v.end());
        set<int> s;
        forin(i,n)
        {
            //s.insert(v[i].first);
            forisn(z,i+1,n)points.push_back({v[i].first,v[z].second});
            for(int z=i-1;z>=0;z--)points.push_back({v[i].first,v[z].second});
        }
        sort(all(points));
        //for(int i=0;i<points.size();i++)
            //cout<<points[i].first<< " - "<<points[i].second<<"\n";
        int may=0;
        forin(i,points.size())
        {
            if(points[i+1].first!=points[i].first){
            may=max((points[i+1].first-points[i].first-1),may);
            }
            //cout<<may<<" -> may \n";
        }
        auto it=lower_bound(all(points),pair<int,int>(may,0));
        //auto it2=upper_bound(all(points),pair<int,int>(may,0));
        int may2=0;int kk=1;
        int i=it-points.begin();
        it=lower_bound(all(points),pair<int,int>(points[i+1].first,0));
        while(it->first==points[i+1].first){
            if(points[i+1].second!=points[i].second)
            {
                    may2=max((points[i+1].second-points[i].second-1),may2);
            }
            i++;
        }

        cout<<may*may2<<"\n";
    }
    return 0;
}

