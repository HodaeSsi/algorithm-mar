#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,m;
    cin>>n>>m;

    vector<pair<int,int>> v;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            int x;
            cin>>x;
            v.push_back({x,i});
        }
    }

    sort(v.begin(),v.end());

    vector<int> lastIndex(n);
    fill(lastIndex.begin(),lastIndex.end(),-1);
    int unique=0;
    int ans=2e9;
    int idx=0;
    while (idx<n*m) {
        if (lastIndex[v[idx].second]==-1) {
            unique++;
        }
        lastIndex[v[idx].second]=idx;

        if (unique==n) {
            int maxVal=v[*max_element(lastIndex.begin(),lastIndex.end())].first;
            int minVal=v[*min_element(lastIndex.begin(),lastIndex.end())].first;

            ans=min(ans,maxVal-minVal);
        }

        idx++;
    }

    cout<<ans;
}
