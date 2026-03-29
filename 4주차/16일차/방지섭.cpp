#include <bits/stdc++.h>
using namespace std;

int a,b,c,k;
int dp[1000001][4]; // 앞 : 0, 오른쪽 : 1, 뒤 : 2, 왼쪽 : 3
void input(){
    cin >> a >> b >> c >> k;
}

void solve(){
    int cur_dis = 0;
    int dp[k+1][4]; for(int i=0;i<k+1;i++) for(int j=0;j<4;j++) dp[i][j] = 2000000000;

    dp[0][0] = 0;

    for(int i=0;i<k+1;i++){
        for(int j=0;j<4;j++){
            if(dp[i][j] == 2000000000) continue;
            if(i+a <= k) dp[i+a][(j+3)%4] = min(dp[i+a][(j+3)%4], dp[i][j] + 1); // 좌로 돌아
            if(i+b <= k) dp[i+b][(j+1)%4] = min(dp[i+b][(j+1)%4], dp[i][j] + 1); // 우로 돌아
            if(i+c <= k) dp[i+c][(j+2)%4] = min(dp[i+c][(j+2)%4], dp[i][j] + 1); // 뒤로 돌아
        }
    }
    if(dp[k][0] == 2000000000) cout << -1;
    else cout << dp[k][0];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}