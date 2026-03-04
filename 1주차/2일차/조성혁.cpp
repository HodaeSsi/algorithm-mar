#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int>> graph[1001]; // graph[i]={j,k} : (i, j) 간선의 가중치는 k
int mst[1001];

int main() {
    int n,m,k;
    cin>>n>>m>>k;

    vector<int> v(k);
    for (int i=0;i<k;i++) cin>>v[i];

    for (int i=0;i<m;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    for (int i=0;i<k;i++) {
        int cur=v[i];
        mst[cur]=1;
        for (int i=0;i<graph[cur].size();i++) {
            pq.push({graph[cur][i].second,graph[cur][i].first});
        }
    }

    int cnt=k;
    int ans=0;
    while (cnt<n) {
        int x=pq.top().second;
        int w=pq.top().first;
        pq.pop();

        if (mst[x]) continue;

        cnt++;
        mst[x]=1;
        ans+=w;

        for (int i=0;i<graph[x].size();i++) {
            if (!mst[graph[x][i].first]) pq.push({graph[x][i].second,graph[x][i].first});
        }
    }

    cout<<ans;
}
