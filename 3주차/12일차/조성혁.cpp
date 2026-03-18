#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,m,l,k;
    cin>>n>>m>>l>>k;

    vector<pair<int,int>> v;
    for (int i=0;i<k;i++) {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }

    int ans=0;
    for (int i=0;i<k;i++) {
        for (int j=0;j<k;j++) {
            int x=v[i].first;
            int y=v[j].second;
            int lx=x+l;
            int ly=y+l;

            int tmp=0;
            for (int idx=0;idx<k;idx++) {
                int nx=v[idx].first;
                int ny=v[idx].second;

                if (x<=nx&&nx<=lx&&y<=ny&&ny<=ly) tmp++;
            }

            ans=max(ans,tmp);
        }
    }

    cout<<k-ans;
}
