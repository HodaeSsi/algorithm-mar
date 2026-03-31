#include <bits/stdc++.h>
using namespace std;

int n,k, dp[50001][3]; // dp[i][j] = i번째까지 소형기관차를 j+1 개 썼을 때의 최대값
vector<int> v, cum_sum, k_cum_sum;  // cum_sum[i] = i번째까지 v의 누적합, k_cum_sum[i] = i-k+1 ~ i번째 v를 더한 누적합.
void input(){
    cin >> n;
    v.resize(n+1); cum_sum.resize(n+1); k_cum_sum.resize(n+1, 0);
    v[0] = cum_sum[0] = k_cum_sum[0] = 0; 
    for(int i=1;i<=n;i++){cin >> v[i]; cum_sum[i] = cum_sum[i-1] + v[i];}
    cin >> k;
    for(int i=k;i<=n;i++) k_cum_sum[i] = cum_sum[i] - cum_sum[i-k]; 
}

void solve(){
    for(int i=1;i<=n;i++) dp[i][0] = max(dp[i-1][0], k_cum_sum[i]);
    for(int i=1;i<3;i++){
        for(int j=i*k;j<=n;j++){
            dp[j][i] = max(dp[j-1][i], dp[j-k][i-1] + k_cum_sum[j]); // 현재 j번째를 안고르고 이전 최대값을 가져오기 or 고르고 하나 덜 골랐을 때 j-k번째 까지의 최대값이랑 더해주기
        }
    }
    cout << dp[n][2];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}