#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v, tree;

void input(){
    cin >> n;
    v.resize(n);
    tree.resize(4*n);
    for(int i=0;i<n;i++) cin >> v[i];
}

int build(int idx, int s, int e){
    if(s == e) return tree[idx] = s;
    int mid = (s+e)/2;
    int l = build(idx*2, s, mid);
    int r = build(idx*2+1, mid+1, e);

    if(v[l] < v[r]) return tree[idx] = l;
    else return tree[idx] = r;
}

int find_min_pos(int idx, int s, int e, int l, int r){ 
    if(e < l || r < s) return -1;
    if(l <= s && e <= r) return tree[idx];

    int mid = (s+e)/2;
    int ll = find_min_pos(idx*2, s, mid, l, r);
    int rr = find_min_pos(idx*2+1, mid+1, e, l, r);

    if(ll == -1) return rr;
    if(rr == -1) return ll;

    if(v[ll] < v[rr]) return ll;
    else return rr;
}

long long solve(int s, int e){
    if(s > e) return 0;
    int mn_idx = find_min_pos(1, 0, n-1, s, e);
    int cd1 = v[mn_idx] * (e - s + 1);
    int cd2 = max(solve(s, mn_idx-1), solve(mn_idx+1, e));
    return max(cd1, cd2);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    build(1, 0, n-1); // min_segment_tree build
    cout << solve(0, n-1);

    return 0;
}