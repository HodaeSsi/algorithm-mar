#include <bits/stdc++.h>
using namespace std;

long long n,m;
vector<long long> v;
list<long long> dif;
void input(){
    cin >> n >> m;
    v.resize(n);
    for(long long i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    for(long long i=1;i<n;i++){
        long long temp = v[i] - v[i-1] - 1;
        if(temp) dif.push_back(temp);
    }
}

void solve(){
    long long ans = 0;
    long long dis = 1;
    while(m > 0){
        // 맨 앞
        if(m > 0){ans += dis; m--;}
        // 중간
        for(auto iter = dif.begin(); iter != dif.end(); iter++){
            if(m == 0) break;
            if(*iter > 0){
                (*iter)--;
                ans += dis;
                m--;
            }
            if(m == 0) break;
            if(*iter > 0){
                (*iter)--;
                ans += dis;
                m--;
            }

            if(*iter == 0){
                dif.erase(iter);
                iter--;
            }
        }
        // 맨 뒤
        if(m > 0){ans += dis; m--;}

        dis++;
    }
    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}