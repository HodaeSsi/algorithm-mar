#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> v;

void input(){
    cin >> n;
    v.resize(n+1);
    for(long long i=0;i<n;i++) cin >> v[i];
    v[n] = 0; // 맨 뒤의 0 짜리 가상의 경계
}

void solve(){
    stack<long long> st;
    long long ans = 0;
 
    for(long long i=0;i<=n;i++){
        while(!st.empty() && v[st.top()] >= v[i]){
            long long height = v[st.top()]; // 높이(세로)
            long long weight;
            st.pop();
            
            if(st.empty()) weight = i; // 비었으면 처음부터 i 까지.
            else weight = i - st.top() - 1; // i와 이때 st.top()의 위치에 경계를 만들어 그 사이의 거리인 weight가 가로 길이가 됨.
            
            ans = max(ans, height * weight);
        }
        st.push(i);
    }
    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}