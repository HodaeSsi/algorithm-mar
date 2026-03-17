#include <bits/stdc++.h>
using namespace std;

string s;
void input(){
    cin >> s;
}

int match_cnt(string s1, string s2){
    int cnt = 0;
    for(auto k : s1){
        if(k == s2[cnt%3]){
            cnt++;
        }
    }
    return cnt;
}

void solve(){
    int s_size = s.size();

    int cnt1 = match_cnt(s, "KSA");
    int left1 = min(cnt1, s_size); // "KSAKSA.." 인 부분 문자열의 최대길이. 

    int cnt2 = match_cnt(s, "SAK");
    int left2 = min(cnt2, s_size-1); // "SAKSAK.." 인 부분 문자열의 최대길이. S는 앞에 K가 붙어야 되기 때문에 s_size - 1 해야함.
    
    int cnt3 = match_cnt(s, "AKS");
    int left3 = min(cnt3, s_size-2); // "AKS..." 

    int mx = max(left1, max(left2, left3)); // 세가지 케이스 중 가장 긴 부분 문자열의 길이
    cout << (s_size - mx) * 2; // 지우고 + 더하고 -> 곱하기 2
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}