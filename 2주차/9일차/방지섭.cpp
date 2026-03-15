#include <bits/stdc++.h>
using namespace std;

long long n;
void input(){
    cin >> n;
}

void solve(){
    long long cnt = 0;
    for(long long i=1;i<=n/2;i++){
        long long temp = i*i + n;
        long long r = sqrt(temp);
        if(r * r == temp){
            cnt++;
            cout << r << '\n';
        }
    }
    if(cnt == 0) cout << -1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}