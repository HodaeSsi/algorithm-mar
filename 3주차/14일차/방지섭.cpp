#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
void input(){
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++) cin >> v[i];
}

void solve(){
    int ones = 0, twos = 0, sum = 0;
    for(int i=0;i<n;i++){
        sum += v[i];
        twos += v[i] / 2;
        ones += v[i] % 2;
    }

    if(sum % 3 != 0){
        cout << "NO";
    }
    else if(ones > twos) cout << "NO";
    else cout << "YES";  
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}