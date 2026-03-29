#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> v[101];
vector<int> parent;
vector<int> depth;

int find(int a){
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

void input(){
    cin >> n >> m;
    parent.resize(n+1);
    depth.resize(n+1, 0);
    for(int i=0;i<n+1;i++) parent[i] = i;
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);

        int aa = find(a), bb = find(b);
        if(aa == bb) continue;
        if(aa > bb) swap(aa, bb);
        parent[aa] = bb;
    }
}

void bfs(int num){
    vector<bool> visited(n+1, false);
    visited[num] = true;
    queue<int> q;
    q.push(num);
    int dep = -1;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            int f = q.front(); q.pop();
            for(auto k : v[f]){
                if(visited[k]) continue;
                visited[k] = true;
                q.push(k);
            }
        }
        dep++;
    }
    depth[num] = dep;
}

struct node{
    int group_num, min_depth, min_idx; 
};

void solve(){
    // 집단 수 구하기
    vector<int> cnt(n+1, 0);
    map<int, pair<int,int>> groups;
    for(int i=1;i<=n;i++){
        int p = find(i);
        if(cnt[p] == 0){
            groups[p] = {INT32_MAX, -1}; // depth, idx
            cnt[p]++;
        }
    }
    // 각 노드에서 시작할 때 깊이 구하기
    for(int i=1;i<=n;i++){ 
        bfs(i);
        int p = find(i);
        if(groups[p].first > depth[i]){
            groups[p].first = depth[i];
            groups[p].second = i;
        }
    }
    set<int> ans;
    for(auto k : groups){
        ans.insert(k.second.second);
    }
    cout << ans.size() << "\n";
    for(auto k : ans) cout << k << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}