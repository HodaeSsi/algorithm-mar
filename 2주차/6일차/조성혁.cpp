#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int d,n,m;
vector<int> v;

// 간격이 최소 x가 되도록 하고 싶은데, x보다 작다면 nxt을 삭제한다.
int remove(int x) {
    int removed=0;
    int cur=v[0];
    for (int i=1;i<v.size();i++) {
        int nxt=v[i];

        if (nxt-cur<x) {
            removed++;
        }
        else cur=nxt;
    }

    return removed;
}

int main() {
    cin>>d>>n>>m;
    v.resize(n);

    for (int i=0;i<n;i++) cin>>v[i];
    v.push_back(0);
    v.push_back(d);

    sort(v.begin(),v.end());

    int left=1;
    int right=d;
    int ans=0;
    while (left<=right) {
        int mid=(left+right)>>1;

        int cnt=remove(mid);
        // m개보다 많이 삭제했다면 간격 줄임
        if (cnt > m) {
            right=mid-1;
        }
        else {
            ans=max(ans,mid);
            left=mid+1;
        }
    }

    cout<<ans;
}
